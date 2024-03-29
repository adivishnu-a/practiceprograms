import cv2
import mediapipe as mp
import numpy as np
from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume

mp_face_mesh = mp.solutions.face_mesh
face_mesh = mp_face_mesh.FaceMesh(min_detection_confidence=0.5, min_tracking_confidence=0.5)
cap = cv2.VideoCapture(0)

devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = cast(interface, POINTER(IAudioEndpointVolume))
flag = 0

current = volume.GetMasterVolumeLevel()

while cap.isOpened():
    success, image = cap.read()

    # Flip the image horizontally for a mirrored view
    # Convert the color space from BGR to RGB
    image = cv2.cvtColor(cv2.flip(image, 1), cv2.COLOR_BGR2RGB)

    # To improve performance, set this as false
    image.flags.writeable = False

    # Process the image using the face_mesh model and get the result
    results = face_mesh.process(image)

    # Now, we can set the image back as writeable
    image.flags.writeable = True

    # Revert the color space from RGB to BGR
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

    img_h, img_w, img_c = image.shape
    face_3d = []
    face_2d = []

    if results.multi_face_landmarks:
        for face_landmarks in results.multi_face_landmarks:
            for idx, lm in enumerate(face_landmarks.landmark):
                if idx == 33 or idx == 263 or idx == 1 or idx == 61 or idx == 291 or idx == 199:
                    if idx == 1:
                        nose_2d = (lm.x * img_w, lm.y * img_h)
                        nose_3d = (lm.x * img_w, lm.y * img_h, lm.z * 8000)

                    x, y = int(lm.x * img_w), int(lm.y * img_h)

                    # Get the 2D Coordinates
                    face_2d.append([x, y])

                    # Get the 3D Coordinates
                    face_3d.append([x, y, lm.z])

                    # Convert it to the NumPy array
            face_2d = np.array(face_2d, dtype=np.float64)

            # Convert it to the NumPy array
            face_3d = np.array(face_3d, dtype=np.float64)

            # The camera matrix
            focal_length = 1 * img_w

            cam_matrix = np.array([[focal_length, 0, img_h / 2],
                                   [0, focal_length, img_w / 2],
                                   [0, 0, 1]])

            # The Distance Matrix
            dist_matrix = np.zeros((4, 1), dtype=np.float64)

            # Solve PnP
            success, rot_vec, trans_vec = cv2.solvePnP(face_3d, face_2d, cam_matrix, dist_matrix)

            # Get rotational matrix
            rmat, jac = cv2.Rodrigues(rot_vec)

            # Get angles
            angles, mtxR, mtxQ, Qx, Qy, Qz = cv2.RQDecomp3x3(rmat)
            x = angles[0] * 360
            y = angles[1] * 360

            # Now, based on the tilt angle, set the direction and make necessary changes to the volume
            if y < -10:
                text = "Looking Left"   # user looking left, so volume focus right-side
                if flag == 0:
                    volume.SetChannelVolumeLevel(0, current - 5.0, None)  # Left
                    volume.SetChannelVolumeLevel(1, current + 5.0, None)  # Right
                    flag = 1
            elif y > 10:
                text = "Looking Right"  # user looking right, so volume focus left-side
                if flag == 0:
                    volume.SetChannelVolumeLevel(0, current + 5.0, None)  # Left
                    volume.SetChannelVolumeLevel(1, current - 5.0, None)  # Right
                    flag = 1
            elif x < -10:
                text = "Looking Down"   # user looking down, so volume focus decreased
                if flag == 0:
                    volume.SetMasterVolumeLevel(current - 6.0, None)
                    flag = 1
            elif x > 10:
                text = "Looking Up"     # user looking up, so volume focus decreased
                if flag == 0:
                    volume.SetMasterVolumeLevel(current - 6.0, None)
                    flag = 1
            else:
                text = "Forward"    # user looking forward, so volume focus increased and equalised
                if flag == 1:
                    volume.SetMasterVolumeLevel(current, None)
                    volume.SetChannelVolumeLevel(0, current, None)  # Left
                    volume.SetChannelVolumeLevel(1, current, None)  # Right
                    flag = 0

            # Display the tilt direction on the image
            cv2.putText(image, text, (20, 20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

    cv2.imshow('Head Pose Estimation', image)

    if cv2.waitKey(5) & 0xFF == 27:
        break

cap.release()

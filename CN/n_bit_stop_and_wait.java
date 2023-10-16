import java.util.Random;

class n_bit_stop_and_wait {
private static final double ERROR_PROBABILITY = 0.2;

private static String simulateChannel(String frame) {
Random random = new Random();
if (random.nextDouble() < ERROR_PROBABILITY) {
return null; // Frame is lost or corrupted
}
return frame;
}

public static void sender(String data, int n) {
String[] frames = new String[(int) Math.ceil((double) data.length() / n)];
for (int i = 0; i < frames.length; i++) {
frames[i] = data.substring(i * n, Math.min((i + 1) * n, data.length()));
}

int seqNumber = 0;

for (String frame : frames) {
System.out.println("Sending frame " + seqNumber + ": " + frame);
boolean ackReceived = false;
while (!ackReceived) {
String transmittedFrame = simulateChannel(frame);
if (transmittedFrame != null) {
System.out.println("Receiver got frame " + seqNumber + " as: " +
transmittedFrame);
if (transmittedFrame.equals("ACK " + seqNumber)) {
ackReceived = true;
seqNumber = 1 - seqNumber;
System.out.println("ACK " + seqNumber + " received\n");
} else {
System.out.println("NAK " + seqNumber + " received. Retransmittingframe " + seqNumber + "\n");
}
} else {
System.out.println("Frame " + seqNumber + " lost/corrupted. Retransmitting frame " + seqNumber + "\n");
}
}
}
}

public static void receiver(String data, int n) {
String[] frames = new String[(int) Math.ceil((double) data.length() / n)];
for (int i = 0; i < frames.length; i++) {

frames[i] = data.substring(i * n, Math.min((i + 1) * n, data.length()));
}

int seqNumber = 0;

for (int i = 0; i < frames.length; i++) {
String frame = frames[i];
if (Math.random() < ERROR_PROBABILITY) {
System.out.println("Receiver received corrupted frame " + seqNumber + ": "
+ frame);
System.out.println("Sending NAK " + seqNumber + "\n");
} else {
System.out.println("Receiver received frame " + seqNumber + ": " + frame);
System.out.println("Sending ACK " + seqNumber + "\n");
}
seqNumber = 1 - seqNumber;
}
}

public static void main(String[] args) {
String data = "0101011101101000"; // Example data to send
int n = 4; // N-bit frames
System.out.println("Sender:");
sender(data, n);

System.out.println("Receiver:");
receiver(data, n);
}

}
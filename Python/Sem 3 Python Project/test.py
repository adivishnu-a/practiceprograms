import pyttsx3
import speech_recognition as sr
import wikipedia
import webbrowser
import os

engine = pyttsx3.init("sapi5")
voices = engine.getProperty("voices")

engine.setProperty('voice', voices[1].id)  # 1 for female and 0 for male voice

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def take_command():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)
    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print("User said:" + query + "\n")
    except Exception as e:
        print(e)
        speak("Sorry, I didnt get you")
        return ""
    return query

speak("Voice assistance activated ")
speak("How can i help you")
while True:
    query = take_command().lower()
    if 'wikipedia' in query:
        speak("Searching Wikipedia ...")
        query = query.replace("wikipedia", '')
        results = wikipedia.summary(query, sentences=2)
        speak("According to wikipedia")
        speak(results)
    elif 'how are you' in query:
        speak("I am fine thank you")
    elif 'are you' in query:
        speak("I am Voice Assistant developed by Group 6")
    elif 'open youtube' in query:
        speak("opening youtube")
        webbrowser.open("youtube.com")
    elif 'open google' in query:
        speak("opening google")
        webbrowser.open("google.com")
    elif 'open bing' in query:
        speak("opening bing")
        webbrowser.open("bing.com")
        webbrowser.open(key)
    elif 'search on bing' in query or 'search in bing' in query:
        speak("What do you want to search for")
        key = take_command()
        key="https://www.bing.com/search?q="+key
        webbrowser.open(key)
    elif 'search on youtube' in query or 'search in youtube' in query:
        speak("What do you want to search for")
        key = take_command()
        key="https://www.youtube.com/results?search_query="+key
        webbrowser.open(key)
    elif 'search on spotify' in query or 'search in spotify' in query:
        speak("What do you want to search for")
        key = take_command()
        key="https://open.spotify.com/search/"+key
        webbrowser.open(key)
    elif 'direction' in query or 'map' in query:
        speak("Where do you want to go to")
        dest = take_command()
        speak("Where are you going from")
        src = take_command()
        area="https://www.google.com/maps/dir/"+src+"/"+dest
        webbrowser.open(area)
    elif 'search' in query:
        speak("What do you want to search for")
        key = take_command()
        key="https://www.google.com/search?q="+key
        webbrowser.open(key)
    elif 'open github' in query:
        speak("opening github")
        webbrowser.open("github.com")
    elif 'open instagram' in query:
        speak("opening instagram")
        webbrowser.open("instagram.com")
    elif 'open twitter' in query:
        speak("opening twitter")
        webbrowser.open("twitter.com")
    elif 'open pinterest' in query:
        speak("opening pinterest")
        webbrowser.open("pinterest.com")
    elif 'open srm website' in query:
        speak("opening srm website")
        webbrowser.open("srmap.edu.in")
    elif 'open spotify' in query:
        speak("opening spotify")
        webbrowser.open("spotify.com")
    elif 'open whatsapp' in query:
        speak("opening whatsapp")
        webbrowser.open("web.whatsapp.com")
    elif 'play music' in query:
        speak("opening music on Spotify")
        webbrowser.open("spotify:user:%userid:playlist:%playlistid:play")
    elif 'change voice' in query:
        speak("Do you want a male voice or female voice?")
        voicename = take_command()
        if "female" in voicename or "girl" in voicename:
            engine.setProperty('voice', voices[1].id)
            speak("Voice Changed")
        elif "male" in voicename or "boy" in voicename:
            engine.setProperty('voice', voices[0].id)
            speak("Voice Changed")
        else:
            speak("Sorry I didn't get that")
    elif 'local disk' in query:
        speak("Which disk do you want to open?")
        diskname = take_command()
        if "C" in diskname or "c" in diskname:
            os.startfile("C:")
        elif "D" in diskname or "d" in diskname:
            os.startfile("D:")
        elif "E" in diskname or "e" in diskname:
            os.startfile("E:")
        elif "F" in diskname or "f" in diskname:
            os.startfile("F:")
        else:
            speak("Sorry I didn't get that")
    elif 'create folder' in query:
        cwd = os.getcwd()
        speak("What is the name of the new folder?")
        foldername = take_command().lower()
        openpath = os.path.join(cwd, foldername)
        os.mkdir(openpath)
        speak("Directory "+query+" created")
    elif 'quit' in query or 'exit' in query or 'stop' in query:
        exit(0)
    else:
        speak("Sorry I didn't get that")
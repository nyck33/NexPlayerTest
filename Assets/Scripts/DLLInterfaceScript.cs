using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Runtime.InteropServices;
using TMPro;

public class DLLInterfaceScript : MonoBehaviour
{
    public Button playPauseButton;
    public GameObject playTimeObject;
    private Text currentTime;
    //get these from dll
    private int currentTimeInt;
    private int numPauseResume;
    //these are for display
    public TextMeshProUGUI numPausesText;
    public TextMeshProUGUI lastPauseText;

    static readonly string numPausesPrefix = "Num PauseResume: ";
    static readonly string lastPausePrefix = "Last Pause: ";

    private bool isPaused;


    [DllImport("NexplayerDll.dll")]
    private static extern void OnPlayPause(int current_playback_time);
    [DllImport("NexplayerDll.dll")]
    private static extern int GetNumberOfPlayPauseEvents();
    [DllImport("NexplayerDll.dll")]
    private static extern int GetLastPlayPauseTimestamp();


    void Start()
    {
        isPaused = false;
        //reset the DLL
        OnPlayPause(0);
        //add listener to PlayPause Button
        //https://docs.unity3d.com/2019.1/Documentation/ScriptReference/UI.Button-onClick.html
        playPauseButton.onClick.AddListener(CallOnPlayPause);
        
        currentTime = playTimeObject.GetComponent<Text>();
        Debug.Log("currentTime: " + currentTime + " type: " + currentTime.GetType());
        Debug.Log("currentTimeText: " + currentTime.text + " type: " + currentTime.text.GetType());

        //returns 0
        numPauseResume = GetNumberOfPlayPauseEvents();
        Debug.Log("numPauseResumeDLL: " + numPauseResume);

    }

    //is called on PlayPause button click
    void CallOnPlayPause()
    {
        if (!isPaused)//playing -> paused
        {
            currentTime = playTimeObject.GetComponent<Text>();
            Debug.Log("currentTime: " + currentTime + " type: " + currentTime.GetType());
            Debug.Log("currentTimeText: " + currentTime.text + " type: " + currentTime.text.GetType());

            //convert to int 
            ConvertTimeToInt();
            //call dll func to update num clicks and last pause time
            OnPlayPause(currentTimeInt);
            isPaused = true;
        }
        else
        {
            isPaused = false;
        }
        
    }


    //
    void ConvertTimeToInt()
    {
        //currentTimeInt = int.Parse(currentTime.text);
        //iterate string, do math to convert HH::MM::SS to seconds
        string currentTimeStr = currentTime.text;
        string hours = "";
        string minutes = "";
        string seconds = "";

        for(int i = 0; i < currentTimeStr.Length; i++)
        {
            //Debug.Log("idx: " + i + " letter: " + currentTimeStr[i]);
            if(i < 2)
            {
                hours += currentTimeStr[i];
            }else if( i > 2 && i < 5)
            {
                minutes += currentTimeStr[i];
            }else if(i > 5)
            {
                seconds += currentTimeStr[i];
            }
        }
        //HH 10 hrs has 36000 seconds, 1 hour has 3600 seconds
        int hoursInt = int.Parse(hours);
        int minutesInt = int.Parse(minutes);
        int secondsInt = int.Parse(seconds);

        currentTimeInt = (hoursInt * 3600) + (minutesInt * 60) + secondsInt;

        Debug.Log("currentTimeInt: " + currentTimeInt);
    }

    // Update is called once per frame

    void Update()
    {
        //call dll funcs
        numPauseResume = GetNumberOfPlayPauseEvents();
        Debug.Log("numPauseResumeDLL: " + numPauseResume);

        int lastPlayTime = GetLastPlayPauseTimestamp();
        //display to TMP
        DisplayToTMP(lastPlayTime);

    }

    
    void DisplayToTMP(int lastPauseResumeFromDLL)
    {
        //before displaying last time convert to HH:MM::SS
        string timeStr = convertIntToHoursMinSeconds(lastPauseResumeFromDLL);
        //set the TMP text
        lastPauseText.text = lastPausePrefix + timeStr;
        numPausesText.text = numPausesPrefix + numPauseResume.ToString();
    }

    string convertIntToHoursMinSeconds(int lastPauseTimeInt)
    {
        string timeStr = "";

        int hours = lastPauseTimeInt / 3600;
        int secondsRem = lastPauseTimeInt % 3600;
        int minutes = secondsRem / 60;
        secondsRem = secondsRem % 60;

        //if hours, minutes or seconds are single digit prefix 0 
        //insert colon
        timeStr += (timeUnitToZeroPrefixedString(hours) + ":");
        timeStr += (timeUnitToZeroPrefixedString(minutes) + ":");
        timeStr += timeUnitToZeroPrefixedString(secondsRem);

        return timeStr;

    }

    string timeUnitToZeroPrefixedString(int timeUnit)
    {
        string timeStr = timeUnit.ToString();
        if (timeStr.Length >= 2)
        {
            return timeStr;
        }
        else
        {
            return "0" + timeStr;
        }
    }
}

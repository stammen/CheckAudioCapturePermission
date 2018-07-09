# CheckAudioCapturePermission
Sample on how to check the Audio Capture privacy setting on Windows 10

## Requirements
* Visual Studio 2017 with Windows Universal App Development package installed
* Windows SDK 17134 (installed with Visual Studio 2017)

## How to Build

* Open the CheckAudioCapturePermission.sln with Visual Studio 2017

* Build and run the CheckAudioCapturePermission app

* Press the Check Audio Capture Permission Button. The app will display the status of the Privacy | Microphone | Microphone Access permissions.
**Note: You will need to enable microphone access for the CheckAudioCapturePermission app.**

## Discussion

There is a bug in RS4 build 17134.137 and earlier that prevents the DeviceAccessInformation.AccessChanged event from firing. This is fixed in an upcoming update to RS4. It is also fixed in RS5.

There is a bug in RS4 build 17134.137 and earlier that prevents DeviceAccessInformation.CurrentStatus from being updated. This is fixed in an upcoming update to RS4. It is also fixed in RS5.





//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace CheckAudioCapturePermission
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

    private:
        void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void OnAccessChanged(Windows::Devices::Enumeration::DeviceAccessInformation ^sender, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs ^args);
        void SetStatus(bool enabled);

        Windows::Devices::Enumeration::DeviceAccessInformation^ m_deviceAccessInformation;

    };
}

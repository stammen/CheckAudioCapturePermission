//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <ppltasks.h>

using namespace CheckAudioCapturePermission;

using namespace Concurrency;
using namespace Platform;
using namespace Windows::Devices::Enumeration;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
    m_deviceAccessInformation = DeviceAccessInformation::CreateFromDeviceClass(DeviceClass::AudioCapture);
    // Note: In unpatched RS4 the OnAccessChanged method will never be called
    // This is fixed in RS5 and an upcoming update to RS4
    m_deviceAccessInformation->AccessChanged += ref new TypedEventHandler<DeviceAccessInformation ^, DeviceAccessChangedEventArgs ^>(this, &MainPage::OnAccessChanged);
}

void MainPage::OnAccessChanged(DeviceAccessInformation ^sender, DeviceAccessChangedEventArgs ^args)
{
    auto status = args->Status;
    SetStatus(status == DeviceAccessStatus::Allowed);
}

void MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    // Note: In unpatched RS4 CurrentStatus is never updated. You will need to recreate DeviceAccessInformation
    // This is fixed in RS5 and an upcoming update to RS4
    // m_deviceAccessInformation = DeviceAccessInformation::CreateFromDeviceClass(DeviceClass::AudioCapture);
    auto status = m_deviceAccessInformation->CurrentStatus;
    SetStatus(status == DeviceAccessStatus::Allowed);
}

void MainPage::SetStatus(bool enabled)
{
    auto dispatcher = Window::Current->CoreWindow->Dispatcher;
    dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([this, enabled]()
    {
        if (enabled)
        {
            permissionText->Text = "Audio Capture permission is granted";
        }
        else
        {
            permissionText->Text = "Audio Capture permission is denied";
        }
    }));
}

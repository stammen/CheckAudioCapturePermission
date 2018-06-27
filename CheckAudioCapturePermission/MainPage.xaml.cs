using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Threading.Tasks;
using Windows.Devices.Enumeration;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Core;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace CheckAudioCapturePermission
{
    public sealed partial class MainPage : Page
    {
        private DeviceAccessInformation m_deviceAccessInformation;
        
        public MainPage()
        {
            this.InitializeComponent();
            
            m_deviceAccessInformation = DeviceAccessInformation.CreateFromDeviceClass(DeviceClass.AudioCapture);
            // The OnAccessChanged event never gets called!
            m_deviceAccessInformation.AccessChanged += new TypedEventHandler<DeviceAccessInformation, DeviceAccessChangedEventArgs>(OnAccessChanged);
        }

        private async void OnAccessChanged(DeviceAccessInformation sender, DeviceAccessChangedEventArgs e)
        {
            var status = e.Status;
            await SetStatus(status == DeviceAccessStatus.Allowed);
        }

        private async void Button_Click(object sender, RoutedEventArgs e)
        {
            // it appears that m_deviceAccessInformation goes stale. Have to recreate it every time! 
            m_deviceAccessInformation = DeviceAccessInformation.CreateFromDeviceClass(DeviceClass.AudioCapture);
            var status = m_deviceAccessInformation.CurrentStatus;
            await SetStatus(status == DeviceAccessStatus.Allowed);
        }

        private async Task SetStatus(bool enabled)
        {
            await Dispatcher.RunAsync(CoreDispatcherPriority.Normal, () =>
            {
                if (enabled)
                {
                    permissionText.Text = "Audio Capture permission is denied";
                }
                else
                {
                    permissionText.Text = "Audio Capture permission is granted";
                }
            });
        }
    }
}

//https://fedoraproject.org/wiki/How_to_debug_Wayland_problems#Screen_capture_is_not_available_with_usual_apps
//https://blog.csdn.net/weixin_29643223/article/details/116952084
//https://wiki.archlinuxcn.org/wiki/%E5%B1%8F%E5%B9%95%E6%8D%95%E8%8E%B7
//https://www.cnblogs.com/qinlangsky/p/13491419.html
//方案调研http://it.taocms.org/11/113758.htm
void test()
{
  //接口查询https://flatpak.github.io/xdg-desktop-portal/docs/
  char * dbus_name= "org.freedesktop.portal.Screenshot";
  char * dbus_name = "org.freedesktop.portal.Desktop";
  //for python
  https://cloud.tencent.com/developer/ask/sof/106954426
}

//优先实现
//https://github.com/LibVNC/x11vnc

/etc/X11/xorg.conf 或 /etc/X11/xorg.conf.d/
/
Section "Device"
    Identifier "FramebufferDevice"
    Driver "fbdev"  # 或者是 "fbdevhw"
    Option "fbdev" "/dev/fb0"  # 指定 Framebuffer 设备
    # 其他设备配置项...
EndSection

/

gnome-screenshot 支持wayland
 gnome-screenshot 或 Flameshot。
https://stackoverflow.com/questions/68341253/how-can-i-take-a-screenshot-on-wayland
   method_name = "Screenshot";
    method_params = g_variant_new ("(bbs)",
                                     TRUE,
                                     FALSE, /* flash */
                                     filename);

    connection = g_application_get_dbus_connection (g_application_get_default ());
    g_dbus_connection_call_sync (connection,
                               "org.gnome.Shell.Screenshot",
                               "/org/gnome/Shell/Screenshot",
                               "org.gnome.Shell.Screenshot",
                               method_name,
                               method_params,
                               NULL,
                               G_DBUS_CALL_FLAGS_NONE,
                               -1,
                               NULL,
                               &error);

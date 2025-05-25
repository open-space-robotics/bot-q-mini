class LGFX : public lgfx::LGFX_Device
{
    lgfx::Panel_GC9A01      _panel_instance;
    lgfx::Bus_SPI       _bus_instance;   // SPIバスのインスタンス
    lgfx::Light_PWM     _light_instance;
  public:
    LGFX(void)
    {
      { // バス制御の設定を行います。
        auto cfg = _bus_instance.config();    // バス設定用の構造体を取得します。
        cfg.spi_host   = 1;
        cfg.spi_mode   = 0;
        cfg.freq_write = 80000000;
        cfg.pin_sclk   = 10;
        cfg.pin_miso   = -1;
        cfg.pin_mosi   = 11;
        cfg.pin_dc     = 8;
        _bus_instance.config(cfg);
        _panel_instance.setBus(&_bus_instance);
      }
      { // 表示パネル制御の設定を行います。
        auto cfg = _panel_instance.config();    // 表示パネル設定用の構造体を取得します。
        cfg.pin_cs           =    9;  // CSが接続されているピン番号   (-1 = disable)
        cfg.pin_rst          =    12;  // RSTが接続されているピン番号  (-1 = disable)
        cfg.panel_width      =   240;  // 実際に表示可能な幅
        cfg.panel_height     =   240;  // 実際に表示可能な高さ
        cfg.offset_x         =     0;  // パネルのX方向オフセット量
        cfg.offset_y         =     0;  // パネルのY方向オフセット量
        cfg.readable         =  true;  // データ読出しが可能な場合 trueに設定
        cfg.invert           =  true;  // パネルの明暗が反転してしまう場合 trueに設定
        _panel_instance.config(cfg);
      }
      {
        auto cfg = _light_instance.config();
        cfg.pin_bl      = 25;
        cfg.pwm_channel = 1;
        _light_instance.config(cfg);
        _panel_instance.setLight(&_light_instance);
      }
      setPanel(&_panel_instance); // 使用するパネルをセットします。
    }
};
object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Textco: TLabel
    Left = 39
    Top = 12
    Width = 130
    Height = 13
    Caption = 'Impossible de se connecter'
  end
  object Labeltcp: TLabel
    Left = 303
    Top = 12
    Width = 100
    Height = 13
    Caption = 'Le serveur est '#233'teint'
  end
  object DMXColor: TLabel
    Left = 11
    Top = 160
    Width = 66
    Height = 13
    Caption = 'Couleurs DMX'
  end
  object Bleu: TButton
    Left = 143
    Top = 247
    Width = 75
    Height = 25
    Caption = 'Bleu'
    TabOrder = 0
    OnClick = BleuClick
  end
  object Connect: TPanel
    Left = 8
    Top = 8
    Width = 17
    Height = 17
    Color = clRed
    ParentBackground = False
    TabOrder = 1
  end
  object Rouge: TButton
    Left = 143
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Rouge'
    TabOrder = 2
    OnClick = RougeClick
  end
  object Vert: TButton
    Left = 143
    Top = 185
    Width = 75
    Height = 25
    Caption = 'Vert'
    TabOrder = 3
    OnClick = VertClick
  end
  object Blanc: TButton
    Left = 8
    Top = 185
    Width = 75
    Height = 25
    Caption = 'Blanc'
    TabOrder = 4
    OnClick = BlancClick
  end
  object ON: TButton
    Left = 8
    Top = 31
    Width = 75
    Height = 25
    Caption = 'ON'
    TabOrder = 5
    OnClick = ONClick
  end
  object Stroboscope: TButton
    Left = 8
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Stroboscope'
    TabOrder = 6
    OnClick = StroboscopeClick
  end
  object Panel1: TPanel
    Left = 89
    Top = 188
    Width = 24
    Height = 18
    Color = clWhite
    ParentBackground = False
    TabOrder = 7
  end
  object PanelBleu: TPanel
    Left = 224
    Top = 250
    Width = 24
    Height = 18
    Color = clBlue
    ParentBackground = False
    TabOrder = 8
  end
  object Panel3: TPanel
    Left = 224
    Top = 219
    Width = 25
    Height = 17
    Color = clRed
    ParentBackground = False
    TabOrder = 9
  end
  object Panel4: TPanel
    Left = 224
    Top = 188
    Width = 25
    Height = 18
    Color = clLime
    ParentBackground = False
    TabOrder = 10
  end
  object OFF: TButton
    Left = 8
    Top = 62
    Width = 75
    Height = 25
    Caption = 'OFF'
    TabOrder = 11
    OnClick = OFFClick
  end
  object ServerON: TButton
    Left = 303
    Top = 31
    Width = 75
    Height = 25
    Caption = 'Server ON'
    TabOrder = 12
    OnClick = ServerONClick
  end
  object ServerOFF: TButton
    Left = 303
    Top = 62
    Width = 75
    Height = 25
    Caption = 'ServerOFF'
    TabOrder = 13
    Visible = False
    OnClick = ServerOFFClick
  end
  object LMessage: TListBox
    Left = 384
    Top = 31
    Width = 185
    Height = 241
    ItemHeight = 13
    TabOrder = 14
  end
  object Timer1: TTimer
    Interval = 40
    OnTimer = Timer1Timer
    Left = 592
    Top = 24
  end
  object DMXServer: TIdTCPServer
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 25010
      end>
    DefaultPort = 25010
    MaxConnections = 50
    OnConnect = DMXServerConnect
    OnExecute = DMXServerExecute
    Left = 592
    Top = 80
  end
end

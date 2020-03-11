object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 808
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lblResultOpenDMX: TLabel
    Left = 8
    Top = 8
    Width = 87
    Height = 13
    Caption = 'lblResultOpenDMX'
  end
  object Label1: TLabel
    Left = 120
    Top = 43
    Width = 31
    Height = 13
    Caption = 'Rouge'
  end
  object Label2: TLabel
    Left = 336
    Top = 43
    Width = 37
    Height = 13
    Caption = 'Blanche'
  end
  object Label3: TLabel
    Left = 271
    Top = 43
    Width = 26
    Height = 13
    Caption = 'Bleue'
  end
  object Label4: TLabel
    Left = 199
    Top = 43
    Width = 26
    Height = 13
    Caption = 'Verte'
  end
  object Label5: TLabel
    Left = 56
    Top = 101
    Width = 3
    Height = 13
  end
  object Label6: TLabel
    Left = 25
    Top = 43
    Width = 60
    Height = 13
    Caption = 'Stroboscope'
  end
  object LabelTimer: TLabel
    Left = 415
    Top = 43
    Width = 26
    Height = 13
    Caption = 'Timer'
  end
  object ScrollBarBleue: TScrollBar
    Left = 280
    Top = 89
    Width = 17
    Height = 163
    Kind = sbVertical
    Max = 255
    PageSize = 0
    Position = 255
    TabOrder = 0
    OnChange = ScrollBarBleueChange
  end
  object ScrollBarVerte: TScrollBar
    Left = 208
    Top = 89
    Width = 17
    Height = 163
    Kind = sbVertical
    Max = 255
    PageSize = 0
    Position = 255
    TabOrder = 1
    OnChange = ScrollBarVerteChange
  end
  object ScrollBarRouge: TScrollBar
    Left = 128
    Top = 89
    Width = 17
    Height = 163
    Kind = sbVertical
    Max = 255
    PageSize = 0
    Position = 255
    TabOrder = 2
    OnChange = ScrollBarRougeChange
  end
  object ScrollBarWhite: TScrollBar
    Left = 352
    Top = 89
    Width = 17
    Height = 163
    Kind = sbVertical
    Max = 255
    PageSize = 0
    Position = 255
    TabOrder = 3
    OnChange = ScrollBarWhiteChange
  end
  object EditWhite: TEdit
    Left = 336
    Top = 62
    Width = 49
    Height = 21
    TabOrder = 4
    OnKeyDown = EditWhiteKeyDown
  end
  object EditBleue: TEdit
    Left = 256
    Top = 62
    Width = 49
    Height = 21
    TabOrder = 5
    OnKeyDown = EditBleueKeyDown
  end
  object EditRouge: TEdit
    Left = 113
    Top = 62
    Width = 49
    Height = 21
    TabOrder = 6
    OnKeyDown = EditRougeKeyDown
  end
  object EditVerte: TEdit
    Left = 193
    Top = 62
    Width = 49
    Height = 21
    TabOrder = 7
    OnKeyDown = EditVerteKeyDown
  end
  object Button1: TButton
    Left = 472
    Top = 177
    Width = 137
    Height = 25
    Caption = 'Affichage de la sequence'
    TabOrder = 8
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 457
    Top = 208
    Width = 168
    Height = 84
    DragMode = dmAutomatic
    Lines.Strings = (
      '')
    ReadOnly = True
    TabOrder = 9
  end
  object EditStrobo: TEdit
    Left = 36
    Top = 62
    Width = 49
    Height = 21
    TabOrder = 10
    OnKeyDown = EditStroboKeyDown
  end
  object ScrollBarStrobo: TScrollBar
    Left = 49
    Top = 89
    Width = 17
    Height = 163
    Kind = sbVertical
    Max = 255
    PageSize = 0
    Position = 255
    TabOrder = 11
    OnChange = ScrollBarStroboChange
  end
  object BoutonCreaSequence: TButton
    Left = 488
    Top = 8
    Width = 113
    Height = 25
    Caption = 'Envoie en BDD'
    TabOrder = 12
    OnClick = BoutonCreaSequenceClick
  end
  object ScrollBarTimer: TScrollBar
    Left = 424
    Top = 89
    Width = 17
    Height = 163
    Kind = sbVertical
    Max = 15
    PageSize = 0
    Position = 15
    TabOrder = 13
    OnChange = ScrollBarTimerChange
  end
  object EditTimer: TEdit
    Left = 408
    Top = 62
    Width = 49
    Height = 21
    TabOrder = 14
    OnKeyDown = EditTimerKeyDown
  end
  object ButtonOFF: TButton
    Left = 167
    Top = 3
    Width = 90
    Height = 25
    Caption = 'OFF/Remise '#224' 0'
    TabOrder = 15
    OnClick = ButtonOFFClick
  end
  object Button2: TButton
    Left = 631
    Top = 96
    Width = 82
    Height = 25
    Caption = 'Ouvrir PS'
    TabOrder = 16
    OnClick = Button2Click
  end
  object MemoArduino: TMemo
    Left = 631
    Top = 136
    Width = 170
    Height = 156
    DragMode = dmAutomatic
    ScrollBars = ssVertical
    TabOrder = 17
  end
  object Button3: TButton
    Left = 725
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Fermer PS'
    TabOrder = 18
    OnClick = Button3Click
  end
  object Timer1: TTimer
    Interval = 50
    OnTimer = Timer1Timer
    Left = 776
  end
  object TimerPortSerie: TTimer
    Interval = 750
    OnTimer = TimerPortSerieTimer
    Left = 736
  end
end

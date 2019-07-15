object settingsForm: TsettingsForm
  Left = 768
  Top = 320
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  BorderWidth = 20
  Caption = 'Ustawienia'
  ClientHeight = 221
  ClientWidth = 444
  Color = clBtnFace
  Constraints.MaxHeight = 300
  Constraints.MaxWidth = 500
  Constraints.MinHeight = 300
  Constraints.MinWidth = 500
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object winingScore: TLabeledEdit
    Left = 88
    Top = 8
    Width = 49
    Height = 21
    EditLabel.Width = 71
    EditLabel.Height = 13
    EditLabel.Caption = 'Do ilu punkt'#243'w'
    LabelPosition = lpLeft
    LabelSpacing = 3
    TabOrder = 0
  end
  object applyButton: TButton
    Left = 24
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Zatwierd'#378
    TabOrder = 1
    OnClick = applyButtonClick
  end
  object discardButton: TButton
    Left = 112
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Anuluj'
    TabOrder = 2
    OnClick = discardButtonClick
  end
  object ballSpeedTrackBar: TTrackBar
    Left = 152
    Top = 40
    Width = 150
    Height = 45
    Max = 5
    Min = 1
    Orientation = trHorizontal
    Frequency = 1
    Position = 2
    SelEnd = 0
    SelStart = 0
    TabOrder = 3
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = ballSpeedTrackBarChange
  end
  object ballSpeed: TLabeledEdit
    Left = 88
    Top = 40
    Width = 49
    Height = 21
    EditLabel.Width = 68
    EditLabel.Height = 13
    EditLabel.Caption = 'Pr'#281'dko'#347#263' pi'#322'ki'
    LabelPosition = lpLeft
    LabelSpacing = 3
    ReadOnly = True
    TabOrder = 4
  end
end

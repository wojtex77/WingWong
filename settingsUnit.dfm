object settingsForm: TsettingsForm
  Left = 768
  Top = 320
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Ustawienia'
  ClientHeight = 261
  ClientWidth = 484
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
    Top = 208
    Width = 75
    Height = 25
    Caption = 'Zatwierd'#378
    TabOrder = 1
    OnClick = applyButtonClick
  end
end

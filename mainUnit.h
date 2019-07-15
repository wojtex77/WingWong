//---------------------------------------------------------------------------

#ifndef mainUnitH
#define mainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>

#include "settingsUnit.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TImage *table;
        TShape *paddleLeft;
        TTimer *timerPaddleLeftDown;
        TTimer *timerPaddleLeftUp;
        TTimer *timerPaddleRightDown;
        TTimer *timerPaddleRightUp;
        TShape *paddleRight;
        TImage *ball;
        TTimer *timerBall;
        TButton *startButton;
        TPanel *infoPanel;
        TLabel *resultBlack;
        TLabel *resultRed;
        TLabel *Label1;
        TButton *resetButton;
        TLabel *result;
        TButton *settingsButton;
        void __fastcall timerPaddleLeftDownTimer(TObject *Sender);
        void __fastcall timerPaddleLeftUpTimer(TObject *Sender);
        void __fastcall timerPaddleRightDownTimer(TObject *Sender);
        void __fastcall timerPaddleRightUpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall timerBallTimer(TObject *Sender);
        void __fastcall startButtonClick(TObject *Sender);
        void __fastcall resetButtonClick(TObject *Sender);
        void __fastcall settingsButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);

        int winingResult;
        int xBallVelocityPointer;
        int yBallVelocityPointer;
        int blackResult;
        int redResult;


        bool checkGameEnd (int redScore, int blackScore);
        void resetPaddlesAndBallPositions ();
        void TMainForm::setButtonsConditions ();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

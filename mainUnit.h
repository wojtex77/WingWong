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
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

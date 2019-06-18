//---------------------------------------------------------------------------

#ifndef settingsUnitH
#define settingsUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TsettingsForm : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TsettingsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TsettingsForm *settingsForm;
//---------------------------------------------------------------------------
#endif

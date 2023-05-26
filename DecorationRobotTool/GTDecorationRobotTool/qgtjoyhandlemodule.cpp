#include "qgtjoyhandlemodule.h"

QGTJoyHandleModule::QGTJoyHandleModule(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

QGTJoyHandleModule::~QGTJoyHandleModule()
{

}

void QGTJoyHandleModule::Update_ActualInfo_JoyHandle()
{
	ui.label_JoyHandle_Button_Status->setText(g_pGlobalUnit->m_strJoy_Btn_Status);
	ui.label_JoyHandle_Pov_Status->setText(g_pGlobalUnit->m_strJoy_Pov_Status);
}

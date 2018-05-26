#include "DXApp.h"

class  TestApp: public DXApp
{
public:
	TestApp(HINSTANCE hInstance);
	~TestApp();

	bool Init() override;
	void Update(float dt) override;
	void Render(float dt) override;
protected:
private:
};

TestApp::TestApp(HINSTANCE hInstance) : DXApp(hInstance)
{

}

TestApp::~TestApp()
{

}

bool TestApp::Init()
{
	return DXApp::Init();
}

void TestApp::Update(float dt)
{

}

void TestApp::Render(float dt)
{
	m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);

	HR(m_pSwapChain->Present(0, 0));
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int nShow)
{
	TestApp tApp(hInstance);
	if (!tApp.Init()) return 1;
	return tApp.Run();
}
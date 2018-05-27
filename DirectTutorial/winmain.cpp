#include <memory>
#include "DXApp.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"
#include "DDSTextureLoader.h"
#include "SimpleMath.h"

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
	std::unique_ptr<DirectX:: SpriteBatch> spriteBatch;
	std::unique_ptr<DirectX::SpriteFont> spriteFont;
	ID3D11ShaderResourceView* m_pTexture;
};

TestApp::TestApp(HINSTANCE hInstance) : DXApp(hInstance)
{

}

TestApp::~TestApp()
{
	Memory::SafeRelease(m_pTexture);
}

bool TestApp::Init()
{
	if (!DXApp::Init())
		return false;
	spriteBatch.reset(new DirectX::SpriteBatch(m_pImmediateContext));
	spriteFont.reset(new DirectX::SpriteFont(m_pDevice, L"Arial.spritefont"));
	HR(DirectX::CreateDDSTextureFromFile(m_pDevice, L"Test.dds", nullptr, &m_pTexture));

	return true;
}

void TestApp::Update(float dt)
{

}

void TestApp::Render(float dt)
{
	m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::CornflowerBlue);
	spriteBatch->Begin();

	spriteBatch->Draw(m_pTexture, DirectX::SimpleMath::Vector2(100, 100));
	spriteFont->DrawString(spriteBatch.get(), L"Hello World", DirectX::SimpleMath::Vector2(300, 300));
	spriteBatch->End();
	HR(m_pSwapChain->Present(0, 0));
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int nShow)
{
	TestApp tApp(hInstance);
	if (!tApp.Init()) return 1;
	return tApp.Run();
}
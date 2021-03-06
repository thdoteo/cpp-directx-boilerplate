#include "heart.h"

Heart::Heart(double x, double y, double r, FloatColor *color)
{
	round = new S2DCycloid(x, y, r, 100, color, [](int i) {return true; }, [](float i) {return (float)(cos(i)); });
	spike = new S2DQuad(x, y - r * 1.5,
		x + r + r / 55, y + r / 55,
		x - r - r / 55, y + r / 55,
		x, y + r / 10,
		color);
}

//--------------------------------------------------------------------------------------
// Register all components of the heart
//--------------------------------------------------------------------------------------
void Heart::Register(ID3D11Device* g_pd3dDevice, D3D11_BUFFER_DESC& bd, D3D11_SUBRESOURCE_DATA& InitData)
{
	spike->Register(g_pd3dDevice, bd, InitData);
	round->Register(g_pd3dDevice, bd, InitData);
}

//--------------------------------------------------------------------------------------
// Render all components of the heart
//--------------------------------------------------------------------------------------
void Heart::Render(ID3D11DeviceContext* g_pImmediateContext, VS_CONSTANT_BUFFER& VsConstData, ID3D11Buffer* g_pConstantBuffer, UINT* stride, UINT* offset)
{
	spike->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
	round->Render(g_pImmediateContext, VsConstData, g_pConstantBuffer, stride, offset);
}
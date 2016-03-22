#include "Sprite2D.h"

namespace JCS_D2DEngine
{
	/**
	 * wchar_t* filename : 圖片檔名
	 * Graphics2D* gfx :  工具讓你渲染圖片
	 */
	Sprite2D::Sprite2D(wchar_t* filename, Graphics2D& gfx)
		: gDevice2D(gfx)
		, bmp(nullptr)
        , m_topLeft()
        , m_bottomRight()
        , m_originScale()
        , m_alpha(1.0f)
        , m_origin()
	{
		HRESULT hr;			// HRESULT for checking errors

		// Create a WIC factory
		IWICImagingFactory* wicFactory = nullptr;
		hr = CoCreateInstance(
			CLSID_WICImagingFactory,		// CLS ID of the object we're making
			nullptr,							// Not part of an aggregate
			CLSCTX_INPROC_SERVER,			// DLL runs in the same process
			IID_IWICImagingFactory,	
			// communicates with the object
			(LPVOID*) &wicFactory);			// The pointer that'll contain our factory
		if (hr != S_OK) 
		{
			MessageBox(nullptr, L"Error", L"Sprite2D:Failed to create WicFactory!", MB_OK);
			return;
		}

		// 製作解碼器 (圖片解碼器)
		IWICBitmapDecoder* wicDecoder = nullptr;
		hr = wicFactory->CreateDecoderFromFilename(
			filename,		// The file name
			nullptr,			// No preferred vendor
			GENERIC_READ,	// We're reading the file, not writing
			WICDecodeMetadataCacheOnLoad,		// Cache on load*
			&wicDecoder);	// The decoder we're making
		if (hr != S_OK) 
		{
			MessageBox(nullptr, L"Error", L"Sprite2D:Failed to create Decoder!", MB_OK);
			return;
		}

		// Read a frame from the image:
		IWICBitmapFrameDecode* wicFrame = nullptr;
		hr = wicDecoder->GetFrame(0, &wicFrame);			// IMPORTANT: 這裡調整"偵數"
		if (hr != S_OK) 
		{
			MessageBox(nullptr, L"Error", L"Sprite2D:Failed to create WicFrame!", MB_OK);
			return;
		}

		// Create a converter
		IWICFormatConverter* wicConverter = nullptr;
		hr = wicFactory->CreateFormatConverter(&wicConverter);
		if (hr != S_OK) 
		{
			MessageBox(nullptr, L"Error", L"Sprite2D:Failed to create WicConverter!", MB_OK);
			return;
		}

		// Setup the converter
		hr = wicConverter->Initialize(
			wicFrame,		// Frame
			GUID_WICPixelFormat32bppPBGRA,	// Pixel Format
			WICBitmapDitherTypeNone,		// Irrelevant
			nullptr,		// No palette needed, irrelevant
			0.0,		// Alpha transparency % irrelevant,
			WICBitmapPaletteTypeCustom		// Irrelevant
		);
		if (hr != S_OK) 
		{
			MessageBox(nullptr, L"Error", L"Sprite2D:Failed to setup WicConverter!", MB_OK);
			return;
		}

		// Use the converter to create an D2D1Bitmap
		gfx.getRenderTarget()->CreateBitmapFromWicBitmap(
			wicConverter,		// Converter
			nullptr,				// D2D1_BITMAP_PROPERTIES
			&bmp				// Destination D2D1 bitmap
		);

        // Get bitmap's bottom right coordinate
        m_spriteWidth = bmp->GetSize().width;
        m_spriteHeight = bmp->GetSize().height;

		SafeReleaseCOM(wicFactory);
		SafeReleaseCOM(wicDecoder);
		SafeReleaseCOM(wicFrame);
		SafeReleaseCOM(wicConverter);
	}

	Sprite2D::~Sprite2D()
	{
		SafeReleaseCOM(bmp);
	}

	void Sprite2D::update(float32 gameTime)
	{
        m_topLeft.x = m_origin.x - m_spriteWidth / 2;
        m_topLeft.y = m_origin.y - m_spriteHeight / 2;
	}

	/**
	 * Draw the bitmap to the render target
	 */
	void Sprite2D::draw()
	{
		gDevice2D.getRenderTarget()->DrawBitmap(
			bmp,		// Bitmap
            D2D1::RectF(m_topLeft.x,
                        m_topLeft.y,
                        m_topLeft.x + m_spriteWidth,
                        m_topLeft.y + m_spriteHeight),       // Destination rectangle
            m_alpha,		// Opacity
			D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
            D2D1::RectF(m_originScale.x,
                        m_originScale.y,
                        m_originScale.x + m_spriteWidth,
                        m_originScale.y + m_spriteHeight)		// Source rectangle
			);
	}
}


//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//                       Created: 2019-12-06                        //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#ifndef _H3BINARYITEMS_HPP_
#define _H3BINARYITEMS_HPP_

#include "../H3_Vector.hpp"
#include "../H3_Set.hpp"
#include "../H3_String.hpp"
#include "../H3_Constants.hpp"

/*
 * This file contains many references to "Binary"
 * which is an artefact from the conversion from WoG source.
 * In fact, these are all GUI assets stored within h3's ResourceManager
 * which is a std::set implemented as a red-black tree (hence the binary term)
 */

namespace h3
{
	// * forward declarations
	_H3API_DECLARE_(H3ARGB888);
	_H3API_DECLARE_(H3RGB888);
	_H3API_DECLARE_(H3RGB555);
	_H3API_DECLARE_(H3RGB565);
	_H3API_DECLARE_(H3HSV);
	_H3API_DECLARE_(H3ResourceManager);
	_H3API_DECLARE_(H3ResourceManagerNode);
	_H3API_DECLARE_(H3ResourceItem);
	_H3API_DECLARE_(H3WavFile);
	_H3API_DECLARE_(H3TextFile);
	_H3API_DECLARE_(H3TextTable);
	_H3API_DECLARE_(H3Palette565);
	_H3API_DECLARE_(H3Palette888);
	_H3API_DECLARE_(H3Palette32);
	_H3API_DECLARE_(H3BasePalette565);
	_H3API_DECLARE_(H3BasePalette888);
	_H3API_DECLARE_(H3Font);
	_H3API_DECLARE_(H3LoadedPcx);
	_H3API_DECLARE_(H3LoadedPcx16);
	_H3API_DECLARE_(H3LoadedPcx24);
	_H3API_DECLARE_(H3DefFrame);
	_H3API_DECLARE_(H3DefGroup);
	_H3API_DECLARE_(H3LoadedDef);

	typedef UINT16 RGB555;
	typedef UINT16 RGB565;

#pragma pack(push, 4)

	/**
	 * @brief 24bit rgb pixel stored as 3 contiguous bytes. Now only exists in H3LoadedPcx24
	 *
	 */
	struct H3RGB888
	{
		UINT8 r;
		UINT8 g;
		UINT8 b;

		/**
		 * @brief approximate darkening by 20%, but faster than hsv
		 */
		_H3API_ VOID Darken20();
		/**
		 * @brief approximate darkening by 50%, but faster than hsv
		 */
		_H3API_ VOID Darken50();
		/**
		 * @brief applies grayscale effect by narrowing the gap between the rgb components
		 */
		_H3API_ VOID GrayScale();
		/**
		 * @brief darkens pixel's color through HSV by specified amount
		 *
		 * @param amount 0..255
		 */
		_H3API_ VOID Darken(const UINT8 amount);
		/**
		 * @brief lightens pixel's color through HSV by amount
		 *
		 * @param amount 0..255
		 */
		_H3API_ VOID Lighten(const UINT8 amount);
		/**
		 * @brief applies rgb mask of specified weight, assuming source pixel has full alpha visibility
		 *
		 * @param red 0..255
		 * @param green 0..255
		 * @param blue 0..255
		 * @param alpha weight component  0..255
		 */
		_H3API_ VOID AlphaDraw(UINT8 red, UINT8 green, UINT8 blue, UINT8 alpha);
		/**
		 * @brief Get equivalent hue as normalized float
		 *
		 * @param red 0..255
		 * @param green 0..255
		 * @param blue 0..255
		 * @return FLOAT 0.0f..1.0f
		 */
		_H3API_ static FLOAT GetHueAsNormalizedFloat(UINT8 red, UINT8 green, UINT8 blue);
		/**
		 * @brief Pack rgb components into a single dword with full alpha visibility
		 *
		 * @param red 0..255
		 * @param green 0..255
		 * @param blue 0..255
		 * @return DWORD packed rgb
		 */
		_H3API_ static DWORD Pack(UINT8 red, UINT8 green, UINT8 blue);
		_H3API_ H3RGB888();
		_H3API_ H3RGB888(DWORD color);
		_H3API_ H3RGB888(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ H3RGB888(const H3RGB565& rgb);
		_H3API_ H3RGB888(const H3ARGB888& rgb);
		_H3API_ VOID operator=(const H3RGB565& col);
		_H3API_ VOID operator=(const H3RGB888& col);
		_H3API_ VOID operator=(const H3ARGB888& col);
		_H3API_ VOID operator=(const UINT16 col);
		_H3API_ VOID operator=(const UINT32 col);
		_H3API_ BOOL operator==(const H3RGB888& col);
#pragma region NamedColors
		_H3API_ static H3RGB888 Regular();
		_H3API_ static H3RGB888 Highlight();
		_H3API_ static H3RGB888 H3Red();
		_H3API_ static H3RGB888 H3Cyan();
		_H3API_ static H3RGB888 H3Green();
		_H3API_ static H3RGB888 H3Blue();
		_H3API_ static H3RGB888 H3Yellow();
		_H3API_ static H3RGB888 H3Orange();
		_H3API_ static H3RGB888 H3Purple();
		_H3API_ static H3RGB888 H3Pink();
		_H3API_ static H3RGB888 AliceBlue();
		_H3API_ static H3RGB888 AntiqueWhite();
		_H3API_ static H3RGB888 Aqua();
		_H3API_ static H3RGB888 Aquamarine();
		_H3API_ static H3RGB888 Azure();
		_H3API_ static H3RGB888 Beige();
		_H3API_ static H3RGB888 Bisque();
		_H3API_ static H3RGB888 Black();
		_H3API_ static H3RGB888 BlanchedAlmond();
		_H3API_ static H3RGB888 Blue();
		_H3API_ static H3RGB888 BlueViolet();
		_H3API_ static H3RGB888 Brown();
		_H3API_ static H3RGB888 BurlyWood();
		_H3API_ static H3RGB888 CadetBlue();
		_H3API_ static H3RGB888 Chartreuse();
		_H3API_ static H3RGB888 Chocolate();
		_H3API_ static H3RGB888 Coral();
		_H3API_ static H3RGB888 CornflowerBlue();
		_H3API_ static H3RGB888 Cornsilk();
		_H3API_ static H3RGB888 Crimson();
		_H3API_ static H3RGB888 Cyan();
		_H3API_ static H3RGB888 DarkBlue();
		_H3API_ static H3RGB888 DarkCyan();
		_H3API_ static H3RGB888 DarkGoldenRod();
		_H3API_ static H3RGB888 DarkGray();
		_H3API_ static H3RGB888 DarkGrey();
		_H3API_ static H3RGB888 DarkGreen();
		_H3API_ static H3RGB888 DarkKhaki();
		_H3API_ static H3RGB888 DarkMagenta();
		_H3API_ static H3RGB888 DarkOliveGreen();
		_H3API_ static H3RGB888 Darkorange();
		_H3API_ static H3RGB888 DarkOrchid();
		_H3API_ static H3RGB888 DarkRed();
		_H3API_ static H3RGB888 DarkSalmon();
		_H3API_ static H3RGB888 DarkSeaGreen();
		_H3API_ static H3RGB888 DarkSlateBlue();
		_H3API_ static H3RGB888 DarkSlateGray();
		_H3API_ static H3RGB888 DarkSlateGrey();
		_H3API_ static H3RGB888 DarkTurquoise();
		_H3API_ static H3RGB888 DarkViolet();
		_H3API_ static H3RGB888 DeepPink();
		_H3API_ static H3RGB888 DeepSkyBlue();
		_H3API_ static H3RGB888 DimGray();
		_H3API_ static H3RGB888 DimGrey();
		_H3API_ static H3RGB888 DodgerBlue();
		_H3API_ static H3RGB888 FireBrick();
		_H3API_ static H3RGB888 FloralWhite();
		_H3API_ static H3RGB888 ForestGreen();
		_H3API_ static H3RGB888 Fuchsia();
		_H3API_ static H3RGB888 Gainsboro();
		_H3API_ static H3RGB888 GhostWhite();
		_H3API_ static H3RGB888 Gold();
		_H3API_ static H3RGB888 GoldenRod();
		_H3API_ static H3RGB888 Gray();
		_H3API_ static H3RGB888 Grey();
		_H3API_ static H3RGB888 Green();
		_H3API_ static H3RGB888 GreenYellow();
		_H3API_ static H3RGB888 HoneyDew();
		_H3API_ static H3RGB888 HotPink();
		_H3API_ static H3RGB888 IndianRed();
		_H3API_ static H3RGB888 Indigo();
		_H3API_ static H3RGB888 Ivory();
		_H3API_ static H3RGB888 Khaki();
		_H3API_ static H3RGB888 Lavender();
		_H3API_ static H3RGB888 LavenderBlush();
		_H3API_ static H3RGB888 LawnGreen();
		_H3API_ static H3RGB888 LemonChiffon();
		_H3API_ static H3RGB888 LightBlue();
		_H3API_ static H3RGB888 LightCoral();
		_H3API_ static H3RGB888 LightCyan();
		_H3API_ static H3RGB888 LightGoldenRodYellow();
		_H3API_ static H3RGB888 LightGray();
		_H3API_ static H3RGB888 LightGrey();
		_H3API_ static H3RGB888 LightGreen();
		_H3API_ static H3RGB888 LightPink();
		_H3API_ static H3RGB888 LightSalmon();
		_H3API_ static H3RGB888 LightSeaGreen();
		_H3API_ static H3RGB888 LightSkyBlue();
		_H3API_ static H3RGB888 LightSlateGray();
		_H3API_ static H3RGB888 LightSlateGrey();
		_H3API_ static H3RGB888 LightSteelBlue();
		_H3API_ static H3RGB888 LightYellow();
		_H3API_ static H3RGB888 Lime();
		_H3API_ static H3RGB888 LimeGreen();
		_H3API_ static H3RGB888 Linen();
		_H3API_ static H3RGB888 Magenta();
		_H3API_ static H3RGB888 Maroon();
		_H3API_ static H3RGB888 MediumAquaMarine();
		_H3API_ static H3RGB888 MediumBlue();
		_H3API_ static H3RGB888 MediumOrchid();
		_H3API_ static H3RGB888 MediumPurple();
		_H3API_ static H3RGB888 MediumSeaGreen();
		_H3API_ static H3RGB888 MediumSlateBlue();
		_H3API_ static H3RGB888 MediumSpringGreen();
		_H3API_ static H3RGB888 MediumTurquoise();
		_H3API_ static H3RGB888 MediumVioletRed();
		_H3API_ static H3RGB888 MidnightBlue();
		_H3API_ static H3RGB888 MintCream();
		_H3API_ static H3RGB888 MistyRose();
		_H3API_ static H3RGB888 Moccasin();
		_H3API_ static H3RGB888 NavajoWhite();
		_H3API_ static H3RGB888 Navy();
		_H3API_ static H3RGB888 OldLace();
		_H3API_ static H3RGB888 Olive();
		_H3API_ static H3RGB888 OliveDrab();
		_H3API_ static H3RGB888 Orange();
		_H3API_ static H3RGB888 OrangeRed();
		_H3API_ static H3RGB888 Orchid();
		_H3API_ static H3RGB888 PaleGoldenRod();
		_H3API_ static H3RGB888 PaleGreen();
		_H3API_ static H3RGB888 PaleTurquoise();
		_H3API_ static H3RGB888 PaleVioletRed();
		_H3API_ static H3RGB888 PapayaWhip();
		_H3API_ static H3RGB888 PeachPuff();
		_H3API_ static H3RGB888 Peru();
		_H3API_ static H3RGB888 Pink();
		_H3API_ static H3RGB888 Plum();
		_H3API_ static H3RGB888 PowderBlue();
		_H3API_ static H3RGB888 Purple();
		_H3API_ static H3RGB888 Red();
		_H3API_ static H3RGB888 RosyBrown();
		_H3API_ static H3RGB888 RoyalBlue();
		_H3API_ static H3RGB888 SaddleBrown();
		_H3API_ static H3RGB888 Salmon();
		_H3API_ static H3RGB888 SandyBrown();
		_H3API_ static H3RGB888 SeaGreen();
		_H3API_ static H3RGB888 SeaShell();
		_H3API_ static H3RGB888 Sienna();
		_H3API_ static H3RGB888 Silver();
		_H3API_ static H3RGB888 SkyBlue();
		_H3API_ static H3RGB888 SlateBlue();
		_H3API_ static H3RGB888 SlateGray();
		_H3API_ static H3RGB888 SlateGrey();
		_H3API_ static H3RGB888 Snow();
		_H3API_ static H3RGB888 SpringGreen();
		_H3API_ static H3RGB888 SteelBlue();
		_H3API_ static H3RGB888 Tan();
		_H3API_ static H3RGB888 Teal();
		_H3API_ static H3RGB888 Thistle();
		_H3API_ static H3RGB888 Tomato();
		_H3API_ static H3RGB888 Turquoise();
		_H3API_ static H3RGB888 Violet();
		_H3API_ static H3RGB888 Wheat();
		_H3API_ static H3RGB888 White();
		_H3API_ static H3RGB888 WhiteSmoke();
		_H3API_ static H3RGB888 Yellow();
		_H3API_ static H3RGB888 YellowGreen();
#pragma endregion
	};
	_H3API_ASSERT_SIZE_(H3RGB888, 3);

	/**
	 * @brief 32bit argb pixel in HD mod
	 *
	 */
	struct H3ARGB888
	{
		UINT8 b;
		UINT8 g;
		UINT8 r;
		UINT8 a;

		/**
		 * @brief pack the pixel components into a single dword
		 *
		 * @return UINT packed pixel value as dword
		 */
		_H3API_ UINT Value() const;
		/**
		 * @brief pack the pixel components into a single dword
		 *
		 * @return UINT packed pixel value as dword
		 */
		_H3API_ UINT operator*() const;
		/**
		 * @brief automatic cast as DWORD
		 *
		 * @return DWORD packed pixel value as dword
		 */
		_H3API_ operator DWORD () const;
		/**
		 * @brief darkens pixel's color through HSV by specified amount
		 * note full transparency is not supported, so this only affects rgb components
		 * @param amount 0..255
		 */
		_H3API_ VOID Darken(const UINT8 amount);
		/**
		 * @brief lightens pixel's color through HSV by specified amount
		 * note full transparency is not supported, so this only affects rgb components
		 * @param amount 0..255
		 */
		_H3API_ VOID Lighten(const UINT8 amount);
		/**
		 * @brief applies grayscale effect by narrowing the gap between the rgb components
		 */
		_H3API_ VOID GrayScale();
		/**
		 * @brief reorders argb components based on legacy drawing, pre - HDmod 5.0RC63
		 */
		_H3API_ VOID Legacy();
		_H3API_ H3ARGB888();
		_H3API_ H3ARGB888(DWORD col);
		_H3API_ H3ARGB888(const H3RGB565& col);
		_H3API_ H3ARGB888(const H3RGB888& col);
		_H3API_ H3ARGB888(const H3ARGB888& col);
		_H3API_ H3ARGB888(UINT8 red, UINT8 blue, UINT8 green);
		/**
		 * @brief pack the pixel components into a single dword
		 *
		 * @return DWORD packed pixel value as dword
		 */
		_H3API_ DWORD GetColor() const;
		_H3API_ VOID operator=(const H3RGB565& col);
		_H3API_ VOID operator=(const H3RGB888& col);
		_H3API_ VOID operator=(const H3ARGB888& col);
		_H3API_ VOID operator=(UINT16 col);
		_H3API_ VOID operator=(UINT32 col);
		_H3API_ BOOL operator==(const H3ARGB888& col);
		/**
		 * @brief approximate lightening by 25% following game logic
		 */
		_H3API_ VOID LightShadow();
		/**
		 * @brief approximate darkening by 50% following game logic
		 */
		_H3API_ VOID DarkShadow();
		/**
		 * @brief blend or superpose a specific mask over the current pixel
		 *
		 * @param col mask to apply
		 */
		_H3API_ VOID Blend(const H3ARGB888& col);
#pragma region NamedColors
		_H3API_ static H3ARGB888 Regular();
		_H3API_ static H3ARGB888 Highlight();
		_H3API_ static H3ARGB888 H3Red();
		_H3API_ static H3ARGB888 H3Cyan();
		_H3API_ static H3ARGB888 H3Green();
		_H3API_ static H3ARGB888 H3Blue();
		_H3API_ static H3ARGB888 H3Yellow();
		_H3API_ static H3ARGB888 H3Orange();
		_H3API_ static H3ARGB888 H3Purple();
		_H3API_ static H3ARGB888 H3Pink();
		_H3API_ static H3ARGB888 AliceBlue();
		_H3API_ static H3ARGB888 AntiqueWhite();
		_H3API_ static H3ARGB888 Aqua();
		_H3API_ static H3ARGB888 Aquamarine();
		_H3API_ static H3ARGB888 Azure();
		_H3API_ static H3ARGB888 Beige();
		_H3API_ static H3ARGB888 Bisque();
		_H3API_ static H3ARGB888 Black();
		_H3API_ static H3ARGB888 BlanchedAlmond();
		_H3API_ static H3ARGB888 Blue();
		_H3API_ static H3ARGB888 BlueViolet();
		_H3API_ static H3ARGB888 Brown();
		_H3API_ static H3ARGB888 BurlyWood();
		_H3API_ static H3ARGB888 CadetBlue();
		_H3API_ static H3ARGB888 Chartreuse();
		_H3API_ static H3ARGB888 Chocolate();
		_H3API_ static H3ARGB888 Coral();
		_H3API_ static H3ARGB888 CornflowerBlue();
		_H3API_ static H3ARGB888 Cornsilk();
		_H3API_ static H3ARGB888 Crimson();
		_H3API_ static H3ARGB888 Cyan();
		_H3API_ static H3ARGB888 DarkBlue();
		_H3API_ static H3ARGB888 DarkCyan();
		_H3API_ static H3ARGB888 DarkGoldenRod();
		_H3API_ static H3ARGB888 DarkGray();
		_H3API_ static H3ARGB888 DarkGrey();
		_H3API_ static H3ARGB888 DarkGreen();
		_H3API_ static H3ARGB888 DarkKhaki();
		_H3API_ static H3ARGB888 DarkMagenta();
		_H3API_ static H3ARGB888 DarkOliveGreen();
		_H3API_ static H3ARGB888 Darkorange();
		_H3API_ static H3ARGB888 DarkOrchid();
		_H3API_ static H3ARGB888 DarkRed();
		_H3API_ static H3ARGB888 DarkSalmon();
		_H3API_ static H3ARGB888 DarkSeaGreen();
		_H3API_ static H3ARGB888 DarkSlateBlue();
		_H3API_ static H3ARGB888 DarkSlateGray();
		_H3API_ static H3ARGB888 DarkSlateGrey();
		_H3API_ static H3ARGB888 DarkTurquoise();
		_H3API_ static H3ARGB888 DarkViolet();
		_H3API_ static H3ARGB888 DeepPink();
		_H3API_ static H3ARGB888 DeepSkyBlue();
		_H3API_ static H3ARGB888 DimGray();
		_H3API_ static H3ARGB888 DimGrey();
		_H3API_ static H3ARGB888 DodgerBlue();
		_H3API_ static H3ARGB888 FireBrick();
		_H3API_ static H3ARGB888 FloralWhite();
		_H3API_ static H3ARGB888 ForestGreen();
		_H3API_ static H3ARGB888 Fuchsia();
		_H3API_ static H3ARGB888 Gainsboro();
		_H3API_ static H3ARGB888 GhostWhite();
		_H3API_ static H3ARGB888 Gold();
		_H3API_ static H3ARGB888 GoldenRod();
		_H3API_ static H3ARGB888 Gray();
		_H3API_ static H3ARGB888 Grey();
		_H3API_ static H3ARGB888 Green();
		_H3API_ static H3ARGB888 GreenYellow();
		_H3API_ static H3ARGB888 HoneyDew();
		_H3API_ static H3ARGB888 HotPink();
		_H3API_ static H3ARGB888 IndianRed();
		_H3API_ static H3ARGB888 Indigo();
		_H3API_ static H3ARGB888 Ivory();
		_H3API_ static H3ARGB888 Khaki();
		_H3API_ static H3ARGB888 Lavender();
		_H3API_ static H3ARGB888 LavenderBlush();
		_H3API_ static H3ARGB888 LawnGreen();
		_H3API_ static H3ARGB888 LemonChiffon();
		_H3API_ static H3ARGB888 LightBlue();
		_H3API_ static H3ARGB888 LightCoral();
		_H3API_ static H3ARGB888 LightCyan();
		_H3API_ static H3ARGB888 LightGoldenRodYellow();
		_H3API_ static H3ARGB888 LightGray();
		_H3API_ static H3ARGB888 LightGrey();
		_H3API_ static H3ARGB888 LightGreen();
		_H3API_ static H3ARGB888 LightPink();
		_H3API_ static H3ARGB888 LightSalmon();
		_H3API_ static H3ARGB888 LightSeaGreen();
		_H3API_ static H3ARGB888 LightSkyBlue();
		_H3API_ static H3ARGB888 LightSlateGray();
		_H3API_ static H3ARGB888 LightSlateGrey();
		_H3API_ static H3ARGB888 LightSteelBlue();
		_H3API_ static H3ARGB888 LightYellow();
		_H3API_ static H3ARGB888 Lime();
		_H3API_ static H3ARGB888 LimeGreen();
		_H3API_ static H3ARGB888 Linen();
		_H3API_ static H3ARGB888 Magenta();
		_H3API_ static H3ARGB888 Maroon();
		_H3API_ static H3ARGB888 MediumAquaMarine();
		_H3API_ static H3ARGB888 MediumBlue();
		_H3API_ static H3ARGB888 MediumOrchid();
		_H3API_ static H3ARGB888 MediumPurple();
		_H3API_ static H3ARGB888 MediumSeaGreen();
		_H3API_ static H3ARGB888 MediumSlateBlue();
		_H3API_ static H3ARGB888 MediumSpringGreen();
		_H3API_ static H3ARGB888 MediumTurquoise();
		_H3API_ static H3ARGB888 MediumVioletRed();
		_H3API_ static H3ARGB888 MidnightBlue();
		_H3API_ static H3ARGB888 MintCream();
		_H3API_ static H3ARGB888 MistyRose();
		_H3API_ static H3ARGB888 Moccasin();
		_H3API_ static H3ARGB888 NavajoWhite();
		_H3API_ static H3ARGB888 Navy();
		_H3API_ static H3ARGB888 OldLace();
		_H3API_ static H3ARGB888 Olive();
		_H3API_ static H3ARGB888 OliveDrab();
		_H3API_ static H3ARGB888 Orange();
		_H3API_ static H3ARGB888 OrangeRed();
		_H3API_ static H3ARGB888 Orchid();
		_H3API_ static H3ARGB888 PaleGoldenRod();
		_H3API_ static H3ARGB888 PaleGreen();
		_H3API_ static H3ARGB888 PaleTurquoise();
		_H3API_ static H3ARGB888 PaleVioletRed();
		_H3API_ static H3ARGB888 PapayaWhip();
		_H3API_ static H3ARGB888 PeachPuff();
		_H3API_ static H3ARGB888 Peru();
		_H3API_ static H3ARGB888 Pink();
		_H3API_ static H3ARGB888 Plum();
		_H3API_ static H3ARGB888 PowderBlue();
		_H3API_ static H3ARGB888 Purple();
		_H3API_ static H3ARGB888 Red();
		_H3API_ static H3ARGB888 RosyBrown();
		_H3API_ static H3ARGB888 RoyalBlue();
		_H3API_ static H3ARGB888 SaddleBrown();
		_H3API_ static H3ARGB888 Salmon();
		_H3API_ static H3ARGB888 SandyBrown();
		_H3API_ static H3ARGB888 SeaGreen();
		_H3API_ static H3ARGB888 SeaShell();
		_H3API_ static H3ARGB888 Sienna();
		_H3API_ static H3ARGB888 Silver();
		_H3API_ static H3ARGB888 SkyBlue();
		_H3API_ static H3ARGB888 SlateBlue();
		_H3API_ static H3ARGB888 SlateGray();
		_H3API_ static H3ARGB888 SlateGrey();
		_H3API_ static H3ARGB888 Snow();
		_H3API_ static H3ARGB888 SpringGreen();
		_H3API_ static H3ARGB888 SteelBlue();
		_H3API_ static H3ARGB888 Tan();
		_H3API_ static H3ARGB888 Teal();
		_H3API_ static H3ARGB888 Thistle();
		_H3API_ static H3ARGB888 Tomato();
		_H3API_ static H3ARGB888 Turquoise();
		_H3API_ static H3ARGB888 Violet();
		_H3API_ static H3ARGB888 Wheat();
		_H3API_ static H3ARGB888 White();
		_H3API_ static H3ARGB888 WhiteSmoke();
		_H3API_ static H3ARGB888 Yellow();
		_H3API_ static H3ARGB888 YellowGreen();
#pragma endregion
	protected:
		_H3API_ PDWORD AsDword();
		_H3API_ PDWORD AsDword() const;
	};
	_H3API_ASSERT_SIZE_(H3ARGB888, 4);

	/**
	 * @brief a 256 argb palette of colors for indexed images, introduced by HDmod
	 *
	 */
	struct H3Palette32
	{
		H3ARGB888 colors[256];

		_H3API_ H3ARGB888& operator[](UINT index);
		_H3API_ H3ARGB888  operator[](UINT index) const;
	};

	/**
	 * @brief 15bits rgb packed in 2 bytes; apparently unused by h3 but the mechanics exist
	 * https://docs.microsoft.com/en-us/windows/desktop/DirectShow/working-with-16-bit-rgb
	 */
	struct H3RGB555
	{
	protected:
		RGB555 bits;
	public:
		_H3API_ UINT8 GetRed();
		_H3API_ UINT8 GetGreen();
		_H3API_ UINT8 GetBlue();
		_H3API_ DWORD UnPack();
		_H3API_ VOID SetBits(WORD color);
		_H3API_ static WORD Pack(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ static DWORD Unpack(RGB555 rgb);
		_H3API_ VOID PackRGB(UINT8 r, UINT8 g, UINT8 b);
	};
	_H3API_ASSERT_SIZE_(H3RGB555, 2);

	/**
	 * @brief 16bits rgb packed in 2 bytes; most common type used without 32bit mode
	 * https://docs.microsoft.com/en-us/windows/desktop/DirectShow/working-with-16-bit-rgb
	 */
	struct H3RGB565
	{
	protected:
		RGB565 bits;
	public:
		/**
		 * @brief retrieve the packed red component
		 *
		 * @return UINT8 0..31
		 */
		_H3API_ UINT8 GetRed() const;
		/**
		 * @brief retrieve the red component in 8bit format
		 *
		 * @return UINT8 0..255
		 */
		_H3API_ UINT8 GetRed8() const;
		/**
		 * @brief retrieve the packed green component
		 *
		 * @return UINT8 0..63
		 */
		_H3API_ UINT8 GetGreen() const;
		/**
		 * @brief retrieve the green component in 8bit format
		 *
		 * @return UINT8 0..255
		 */
		_H3API_ UINT8 GetGreen8() const;
		/**
		 * @brief retrieve the packed blue component
		 *
		 * @return UINT8 0..31
		 */
		_H3API_ UINT8 GetBlue() const;
		/**
		 * @brief retrieve the blue component in 8bit format
		 *
		 * @return UINT8 0..255
		 */
		_H3API_ UINT8 GetBlue8() const;
		/**
		 * @brief retrieves the rgb components in 24bit format
		 *
		 * @return DWORD 0x000000..0xFFFFFF
		 */
		_H3API_ DWORD GetRGB888() const;
		/**
		 * @brief Get a copy of the packed rgb components
		 *
		 * @return RGB565 color packed in 2 bytes
		 */
		_H3API_ RGB565 GetBits() const;
		_H3API_ H3RGB565();
		_H3API_ H3RGB565(RGB565 rgb);
		_H3API_ H3RGB565(UINT8 r, UINT8 g, UINT8 b);
		_H3API_ H3RGB565(DWORD color);
		_H3API_ H3RGB565(const H3RGB888& color);
		_H3API_ H3RGB565(const H3ARGB888& color);
		_H3API_ VOID operator=(const H3RGB565& col);
		_H3API_ VOID operator=(const H3RGB888& col);
		_H3API_ VOID operator=(const H3ARGB888& col);
		_H3API_ VOID operator=(const UINT16 col);
		_H3API_ VOID operator=(const UINT32 col);
		_H3API_ BOOL operator==(const H3RGB565& col);
		/**
		 * @brief automatic cast as 2 bytes WORD
		 *
		 * @return WORD color packed in 2 bytes
		 */
		_H3API_ operator WORD () const;
		/**
		 * @brief Get a copy of the packed rgb components
		 *
		 * @return WORD color packed in 2 bytes
		 */
		_H3API_ WORD Value() const;
		/**
		 * @brief Set the packed color to the specified value
		 *
		 * @param color packed 16bit rgb
		 */
		_H3API_ VOID SetBits(WORD color);
		/**
		 * @brief Set the pixel's components
		 *
		 * @param r red component 0..255
		 * @param g green component 0..255
		 * @param b blue component 0..255
		 */
		_H3API_ VOID PackRGB565(UINT8 r, UINT8 g, UINT8 b);
		/**
		 * @brief Set the pixel's components
		 *
		 * @param rgb color to use
		 */
		_H3API_ VOID Pack(H3RGB888& rgb);
		/**
		 * @brief transform any rgb components into a packed 16bit pixel
		 *
		 * @param r red component 0..255
		 * @param g green component 0..255
		 * @param b blue component 0..255
		 * @return WORD packed 16bit color
		 */
		_H3API_ static WORD  Pack(UINT8 r, UINT8 g, UINT8 b);
		/**
		 * @brief transform a packed 16bit color into a 24bit pixel
		 *
		 * @param rgb 16bit color to unpack
		 * @return DWORD color without alpha component 0x000000..0xFFFFFF
		 */
		_H3API_ static DWORD Unpack(RGB565 rgb);
		/**
		 * @brief darkens pixel's color by specified amount
		 *
		 * @param amount 0..255
		 */
		_H3API_ VOID Darken(UINT8 amount);
		/**
		 * @brief lightens pixel's color by specified amount
		 *
		 * @param amount 0..255
		 */
		_H3API_ VOID Lighten(UINT8 amount);
		/**
		 * @brief applies grayscale effect by narrowing the gap between the rgb components
		 */
		_H3API_ VOID GrayScale();
		/**
		 * @brief darkens by 25% as performed by h3, using default masks
		 * i.e. rgb components are reduced to 75% of their current value
		 */
		_H3API_ VOID LightShadow();
		/**
		 * @brief darkens by 25% as performed by h3, using specified masks
		 * i.e. rgb components are reduced to 75% of their current value
		 * @param mask50 a mask representing 50% rgb components
		 * @param mask25 a mask representing 25% rgb components
		 */
		_H3API_ VOID LightShadow(RGB565 mask50, RGB565 mask25);
		/**
		 * @brief darkens by 50% as performed by h3, using default mask
		 * i.e. rgb components are reduced to 50% of their current value
		 */
		_H3API_ VOID DarkShadow();
		/**
		 * @brief darkens by 50% as performed by h3, using specified mask
		 * i.e. rgb components are reduced to 50% of their current value
		 * @param mask a mask representing 50% rgb components
		 */
		_H3API_ VOID DarkShadow(RGB565 mask);
		/**
		 * @brief Blend 2 colors together to obtain a new one
		 *
		 * @param col the color to mix
		 */
		_H3API_ VOID Blend(const H3RGB565& col);
		/**
		 * @brief Blend 2 colors together to obtain a new one, with an upper cap specified by a mask
		 *
		 * @param col the color to mix
		 * @param mask upper limit for blending of source and \p col
		 */
		_H3API_ VOID Blend(const H3RGB565& col, RGB565 mask);
#pragma region NamedColors
		_H3API_ static RGB565 Regular();
		_H3API_ static RGB565 Highlight();
		_H3API_ static RGB565 H3Red();
		_H3API_ static RGB565 H3Cyan();
		_H3API_ static RGB565 H3Green();
		_H3API_ static RGB565 H3Blue();
		_H3API_ static RGB565 H3Yellow();
		_H3API_ static RGB565 H3Orange();
		_H3API_ static RGB565 H3Purple();
		_H3API_ static RGB565 H3Pink();
		_H3API_ static RGB565 AliceBlue();
		_H3API_ static RGB565 AntiqueWhite();
		_H3API_ static RGB565 Aqua();
		_H3API_ static RGB565 Aquamarine();
		_H3API_ static RGB565 Azure();
		_H3API_ static RGB565 Beige();
		_H3API_ static RGB565 Bisque();
		_H3API_ static RGB565 Black();
		_H3API_ static RGB565 BlanchedAlmond();
		_H3API_ static RGB565 Blue();
		_H3API_ static RGB565 BlueViolet();
		_H3API_ static RGB565 Brown();
		_H3API_ static RGB565 BurlyWood();
		_H3API_ static RGB565 CadetBlue();
		_H3API_ static RGB565 Chartreuse();
		_H3API_ static RGB565 Chocolate();
		_H3API_ static RGB565 Coral();
		_H3API_ static RGB565 CornflowerBlue();
		_H3API_ static RGB565 Cornsilk();
		_H3API_ static RGB565 Crimson();
		_H3API_ static RGB565 Cyan();
		_H3API_ static RGB565 DarkBlue();
		_H3API_ static RGB565 DarkCyan();
		_H3API_ static RGB565 DarkGoldenRod();
		_H3API_ static RGB565 DarkGray();
		_H3API_ static RGB565 DarkGrey();
		_H3API_ static RGB565 DarkGreen();
		_H3API_ static RGB565 DarkKhaki();
		_H3API_ static RGB565 DarkMagenta();
		_H3API_ static RGB565 DarkOliveGreen();
		_H3API_ static RGB565 Darkorange();
		_H3API_ static RGB565 DarkOrchid();
		_H3API_ static RGB565 DarkRed();
		_H3API_ static RGB565 DarkSalmon();
		_H3API_ static RGB565 DarkSeaGreen();
		_H3API_ static RGB565 DarkSlateBlue();
		_H3API_ static RGB565 DarkSlateGray();
		_H3API_ static RGB565 DarkSlateGrey();
		_H3API_ static RGB565 DarkTurquoise();
		_H3API_ static RGB565 DarkViolet();
		_H3API_ static RGB565 DeepPink();
		_H3API_ static RGB565 DeepSkyBlue();
		_H3API_ static RGB565 DimGray();
		_H3API_ static RGB565 DimGrey();
		_H3API_ static RGB565 DodgerBlue();
		_H3API_ static RGB565 FireBrick();
		_H3API_ static RGB565 FloralWhite();
		_H3API_ static RGB565 ForestGreen();
		_H3API_ static RGB565 Fuchsia();
		_H3API_ static RGB565 Gainsboro();
		_H3API_ static RGB565 GhostWhite();
		_H3API_ static RGB565 Gold();
		_H3API_ static RGB565 GoldenRod();
		_H3API_ static RGB565 Gray();
		_H3API_ static RGB565 Grey();
		_H3API_ static RGB565 Green();
		_H3API_ static RGB565 GreenYellow();
		_H3API_ static RGB565 HoneyDew();
		_H3API_ static RGB565 HotPink();
		_H3API_ static RGB565 IndianRed();
		_H3API_ static RGB565 Indigo();
		_H3API_ static RGB565 Ivory();
		_H3API_ static RGB565 Khaki();
		_H3API_ static RGB565 Lavender();
		_H3API_ static RGB565 LavenderBlush();
		_H3API_ static RGB565 LawnGreen();
		_H3API_ static RGB565 LemonChiffon();
		_H3API_ static RGB565 LightBlue();
		_H3API_ static RGB565 LightCoral();
		_H3API_ static RGB565 LightCyan();
		_H3API_ static RGB565 LightGoldenRodYellow();
		_H3API_ static RGB565 LightGray();
		_H3API_ static RGB565 LightGrey();
		_H3API_ static RGB565 LightGreen();
		_H3API_ static RGB565 LightPink();
		_H3API_ static RGB565 LightSalmon();
		_H3API_ static RGB565 LightSeaGreen();
		_H3API_ static RGB565 LightSkyBlue();
		_H3API_ static RGB565 LightSlateGray();
		_H3API_ static RGB565 LightSlateGrey();
		_H3API_ static RGB565 LightSteelBlue();
		_H3API_ static RGB565 LightYellow();
		_H3API_ static RGB565 Lime();
		_H3API_ static RGB565 LimeGreen();
		_H3API_ static RGB565 Linen();
		_H3API_ static RGB565 Magenta();
		_H3API_ static RGB565 Maroon();
		_H3API_ static RGB565 MediumAquaMarine();
		_H3API_ static RGB565 MediumBlue();
		_H3API_ static RGB565 MediumOrchid();
		_H3API_ static RGB565 MediumPurple();
		_H3API_ static RGB565 MediumSeaGreen();
		_H3API_ static RGB565 MediumSlateBlue();
		_H3API_ static RGB565 MediumSpringGreen();
		_H3API_ static RGB565 MediumTurquoise();
		_H3API_ static RGB565 MediumVioletRed();
		_H3API_ static RGB565 MidnightBlue();
		_H3API_ static RGB565 MintCream();
		_H3API_ static RGB565 MistyRose();
		_H3API_ static RGB565 Moccasin();
		_H3API_ static RGB565 NavajoWhite();
		_H3API_ static RGB565 Navy();
		_H3API_ static RGB565 OldLace();
		_H3API_ static RGB565 Olive();
		_H3API_ static RGB565 OliveDrab();
		_H3API_ static RGB565 Orange();
		_H3API_ static RGB565 OrangeRed();
		_H3API_ static RGB565 Orchid();
		_H3API_ static RGB565 PaleGoldenRod();
		_H3API_ static RGB565 PaleGreen();
		_H3API_ static RGB565 PaleTurquoise();
		_H3API_ static RGB565 PaleVioletRed();
		_H3API_ static RGB565 PapayaWhip();
		_H3API_ static RGB565 PeachPuff();
		_H3API_ static RGB565 Peru();
		_H3API_ static RGB565 Pink();
		_H3API_ static RGB565 Plum();
		_H3API_ static RGB565 PowderBlue();
		_H3API_ static RGB565 Purple();
		_H3API_ static RGB565 Red();
		_H3API_ static RGB565 RosyBrown();
		_H3API_ static RGB565 RoyalBlue();
		_H3API_ static RGB565 SaddleBrown();
		_H3API_ static RGB565 Salmon();
		_H3API_ static RGB565 SandyBrown();
		_H3API_ static RGB565 SeaGreen();
		_H3API_ static RGB565 SeaShell();
		_H3API_ static RGB565 Sienna();
		_H3API_ static RGB565 Silver();
		_H3API_ static RGB565 SkyBlue();
		_H3API_ static RGB565 SlateBlue();
		_H3API_ static RGB565 SlateGray();
		_H3API_ static RGB565 SlateGrey();
		_H3API_ static RGB565 Snow();
		_H3API_ static RGB565 SpringGreen();
		_H3API_ static RGB565 SteelBlue();
		_H3API_ static RGB565 Tan();
		_H3API_ static RGB565 Teal();
		_H3API_ static RGB565 Thistle();
		_H3API_ static RGB565 Tomato();
		_H3API_ static RGB565 Turquoise();
		_H3API_ static RGB565 Violet();
		_H3API_ static RGB565 Wheat();
		_H3API_ static RGB565 White();
		_H3API_ static RGB565 WhiteSmoke();
		_H3API_ static RGB565 Yellow();
		_H3API_ static RGB565 YellowGreen();
#pragma endregion
	};
	_H3API_ASSERT_SIZE_(H3RGB565, 2);

	/**
	 * @brief approximate HSV pixel without floats for smarter color manipulation
	 *
	 */
	struct H3HSV
	{
	protected:
		UINT8 h;
		UINT8 s;
		UINT8 v;
	public:
		_H3API_ H3HSV();
		_H3API_ H3HSV(H3HSV& other);
		_H3API_ H3HSV(const H3RGB888& rgb);
		// * based on https://stackoverflow.com/a/14733008
		_H3API_ H3HSV&   ConvertFromRgb888(const H3RGB888& rgb);
		_H3API_ H3RGB888 ConvertToRgb888() const;
		_H3API_ VOID AddSaturation(UINT8 saturation);
		_H3API_ VOID RemoveSaturation(UINT8 saturation);
		_H3API_ VOID SetHue(UINT8 hue);
		_H3API_ VOID AddValue(UINT8 value);
		_H3API_ VOID RemoveValue(UINT8 value);
	};

	struct H3ResourceItemData
	{
		CHAR            m_name[12];
		UINT            m_nameEnd;
		H3ResourceItem* m_item;

		_H3API_ H3ResourceItemData(LPCSTR name);
		_H3API_ BOOL8 operator<(const H3ResourceItemData& other) const;
	};

	// * a binary tree to hold game assets
	struct H3ResourceManager : H3Set<H3ResourceItemData, 0x69E604>
	{
		_H3API_ Node* FindItem(LPCSTR name);
		_H3API_ VOID  AddItem(H3ResourceItem* item);
		_H3API_ VOID  RemoveItem(Node* node);
		_H3API_ VOID  RemoveItem(const iterator& iter);
		_H3API_ VOID  RemoveItem(LPCSTR name);
	};

	struct H3ResourceItem
	{
		// constructor 0x558970
		friend H3ResourceManager;
	protected:
		struct ResourceItemVTable
		{
			typedef H3ResourceItem*(__thiscall* VDestroy)(H3ResourceItem*, BOOL8);
			typedef VOID(__thiscall* VDeref)(H3ResourceItem*);
			typedef UINT(__thiscall* VGetSize)(H3ResourceItem*);

			VDestroy vdestroy; // 0x5589C0, called by dereference
			VDeref   vEraseFromResourceManager; // 0x55D300
			VGetSize vGetSize;
		}*vTable;
		// * +4
		CHAR name[12];
		// * +10
		UINT nameEnd; // always 0
		// * +14
		INT32 type; // arg3 from constructor
		// * +18
		INT32 ref; // the number of times it is being used
	public:
		_H3API_ H3ResourceItem* InitiateResource(LPCSTR name, INT type);
		_H3API_ VOID Dereference();
		_H3API_ VOID AddToResourceManager();
		_H3API_ VOID IncreaseReferences();
		_H3API_ LPCSTR GetName() const;
		_H3API_ ~H3ResourceItem();
	};
	_H3API_ASSERT_SIZE_(H3ResourceItem, 0x1C);

	// * from breakpoint at constructor, the following items are all H3ResourceItem subclasses
	struct H3WavFile : public H3ResourceItem
	{
		// * +1C
		HANDLE hSample; // from SoundMgr
		// * +20
		PUINT8 buffer;
		// * +24
		DWORD bufferSize;
		// * +28 fields of _RTL_CRITICAL_SECTION
		HANDLE lockSemaphore;
		// * +2C
		ULONG_PTR spinCount;
		// * +30
		PRTL_CRITICAL_SECTION_DEBUG debugInfo;

		_H3API_ static H3WavFile* Load(LPCSTR name);

		_H3API_ H3WavFile(LPCSTR name);
		_H3API_ H3WavFile(LPCSTR name, PUINT8 buffer, DWORD bufferSize);
	};
	_H3API_ASSERT_SIZE_(H3WavFile, 0x34);

	// * text file with a single column of text
	struct H3TextFile : public H3ResourceItem
	{
	protected:
		// * +1C list of rows holding text, single column
		H3Vector<LPCSTR> text;
		// * +2C
		LPCSTR buffer;
		// the buffer size is not stored for this format
	public:
		// * using the index from TxtEdit
		_H3API_ LPCSTR  GetText(UINT32 row) const;
		_H3API_ LPCSTR  GetText(UINT32 row);
		_H3API_ VOID    UnLoad();
		_H3API_ LPCSTR& operator[](UINT row);
		_H3API_ LPCSTR* begin();
		_H3API_ LPCSTR* end();

		_H3API_ static H3TextFile* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3TextFile, 0x30);

	// * text file with several columns of text
	struct H3TextTable : public H3ResourceItem
	{
		struct iterator
		{
		protected:
			H3Vector<LPCSTR>** data;
		public:
			_H3API_ iterator(H3Vector<LPCSTR>** vec);
			_H3API_ iterator& operator++();
			_H3API_ iterator operator++(int);
			_H3API_ H3Vector<LPCSTR>& operator*();
			_H3API_ H3Vector<LPCSTR>* operator->();
			_H3API_ LPCSTR operator[](UINT column);
			_H3API_ BOOL   operator==(const iterator& other);
			_H3API_ BOOL   operator!=(const iterator& other);
		};

	protected:
		// * +1C list of rows holding lists of column text
		H3Vector<H3Vector<LPCSTR>*> text;
		// * +2C
		LPCSTR buffer;
		// * +30
		UINT bufferSize;
	public:
		_H3API_ H3Vector<H3Vector<LPCSTR>*>& GetText();
		_H3API_ H3Vector<LPCSTR>& operator[](UINT row);
		_H3API_ UINT32   CountRows() const;
		_H3API_ VOID     UnLoad();
		_H3API_ iterator begin();
		_H3API_ iterator end();
		_H3API_ static H3TextTable* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3TextTable, 0x34);

	struct H3Palette565 : public H3ResourceItem
	{
		// * +1C
		union {
			struct {
				H3RGB565 color[256];
			};
			struct {
				H3RGB565   unusedColors[254];
				H3Palette32* palette32;
			};
		};

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ VOID RotateColors(INT min_index, INT max_index, INT count = -1);
		_H3API_ H3Palette565* Initiate();
		// * as of HDmod 5.0 RC 63, Palette565 now contains a buffer o ARGB888 colors[256] located at &color[254]
		// * http://heroescommunity.com/viewthread.php3?TID=44581&PID=1503736#focus
		_H3API_ H3Palette32* Get32bitColors();
		_H3API_ VOID CopyPalette(const H3Palette565& source);
		_H3API_ VOID CopyPalette(const H3BasePalette565& source);

		_H3API_ H3RGB565& operator[](UINT index);
		_H3API_ H3RGB565 operator[](UINT index) const;

		_H3API_ H3Palette32 Convert() const;

		_H3API_ VOID Init(const H3BasePalette565& palette);
	};
	_H3API_ASSERT_SIZE_(H3Palette565, 540);

	struct H3Palette888 : public H3ResourceItem
	{
		// * +1C
		H3RGB888 color[256];

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ H3Palette888* Initiate();

		_H3API_ H3RGB888& operator[](UINT index);
		_H3API_ const H3RGB888& operator[](UINT index) const;
		_H3API_ VOID Init(const H3BasePalette888& palette);

		_H3API_ H3Palette32 Convert() const;
	};
	_H3API_ASSERT_SIZE_(H3Palette888, 0x31C);

	// * same functionality as H3Palette565 except it does not derive from H3ResourceItem
	// * this type is used by H3LoadedPcx and H3Font
	struct H3BasePalette565
	{
	protected:
		h3align _f_00[28];
	public:
		// * +1C
		union
		{
		#ifdef _H3API_CPLUSPLUS11_
			H3RGB565 color[256];
		#else // older VS have issues with unions and non-default constructors
			RGB565 color[256];
		#endif
			struct
			{
				H3RGB565 unusedColors[254];
				H3ARGB888* palette32;
			};
		};

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ VOID RotateColors(INT min_index, INT max_index, INT count = -1);
		// * as of HDmod 5.0 RC 63, Palette565 now contains a buffer of ARGB888 colors[256] located at &color[254]
		// * http://heroescommunity.com/viewthread.php3?TID=44581&PID=1503736#focus
		_H3API_ H3Palette32* Get32bitColors();
		_H3API_ VOID CopyPalette(H3Palette565& source);
		_H3API_ VOID CopyPalette(H3BasePalette565& source);

		_H3API_ VOID InitiateFromPalette888(const H3BasePalette888& palette);

		_H3API_ H3RGB565& operator[](UINT index);
		_H3API_ H3RGB565 operator[](UINT index) const;
		_H3API_ H3BasePalette565();
		_H3API_ H3BasePalette565(const H3Palette888& palette);
		_H3API_ H3BasePalette565(const H3BasePalette888& palette);
		_H3API_ ~H3BasePalette565();

		_H3API_ H3Palette32 Convert() const;

#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3BasePalette565(H3BasePalette565&& other);
		_H3API_ H3BasePalette565& operator=(H3BasePalette565&& other);
#endif
	};
	_H3API_ASSERT_SIZE_(H3BasePalette565, 540);

	// * same functionality as H3Palette888 except it does not derive from H3ResourceItem
	// * this type is used by H3LoadedPcx and H3Font
	struct H3BasePalette888
	{
	protected:
		h3align _f_00[28];
	public:
		// * +1C
		H3RGB888 color[256];

		_H3API_ VOID ColorToPlayer(INT id);
		_H3API_ ~H3BasePalette888();
		_H3API_ H3BasePalette888();
		_H3API_ H3RGB888& operator[](UINT index);
		_H3API_ const H3RGB888& operator[](UINT index) const;

		_H3API_ H3Palette32 Convert() const;

#ifdef _H3API_CPLUSPLUS11_
		_H3API_ H3BasePalette888(H3BasePalette888&& other);
		_H3API_ H3BasePalette888& operator=(H3BasePalette888&& other);
#endif
	};
	_H3API_ASSERT_SIZE_(H3BasePalette888, 0x31C);

	struct H3Font : public H3ResourceItem
	{
	protected:
		h3unk _f_1C[5];
	public:
		// * +21
		INT8 height;
	protected:
		h3unk _f_22[26];
	public:
		// * +3C
		struct FontSpacing
		{
			INT32 leftMargin;
			INT32 span;
			INT32 rightMargin;
		}width[256]; // used to calculate line width
		// * +C3C
		UINT32 bufferOffsets[256]; // referenced at 0x4B4F1C
		// * +103C
		H3BasePalette565 palette;
		// * 1258
		PUINT8 bitmapBuffer; // how the characters look
		// * +125C
		INT32 bufferSize;

		_H3API_ INT32 GetLinesCountInText(LPCSTR str, INT32 width);
		_H3API_ INT32 GetMaxLineWidth(LPCSTR str);
		_H3API_ INT32 GetMaxWordWidth(LPCSTR str);
		_H3API_ VOID  SplitTextIntoLines(LPCSTR text, INT32 textWidth, H3Vector<H3String>& stringVector);

		_H3API_ VOID TextDraw(H3LoadedPcx16* pcx, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height,
			NH3Dlg::TextColor::eTextColor colorIndex = NH3Dlg::TextColor::REGULAR,
			NH3Dlg::TextAlignment::eTextAlignment alignment = NH3Dlg::TextAlignment::MIDDLE_CENTER);

		_H3API_ static H3Font* Load(LPCSTR name);

		/**
		 * @brief Access font buffer at starting position of specified character
		 * @param character_id Index of the ascii character 0..255
		 * @return Buffer to specified location
		 */
		_H3API_ PUINT8 GetChar(UINT32 character_id);
	};
	_H3API_ASSERT_SIZE_(H3Font, 0x1260);

	struct H3LoadedPcx : public H3ResourceItem // size 0x56C // vt 63BA14
	{
		// * +1C
		INT32 bufSize;
		// * +20
		INT32 bufSizeUnk;
		// * +24
		INT32 width;
		// * +28
		INT32 height;
		// * +2C
		INT32 scanlineSize;
		// * +30
		// * 256-color indexed buffer
		PUINT8 buffer;
		// * +34
		H3BasePalette565 palette565;
		// * +250
		H3BasePalette888 palette888;

		_H3API_ VOID DrawToPcx16(int srcX, int srcY, int dx, int dy, H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors);
		_H3API_ VOID DrawToPcx16(H3LoadedPcx16* dest, int destX, int destY, BOOL skip_transparent_colors);
		_H3API_ VOID DrawToPcx(int src_x, int src_y, int dx, int dy, H3LoadedPcx* pcx_dest, int dest_x = 0, int dest_y = 0, BOOL copy_palette = TRUE);
		// * returns row start in buffer
		_H3API_ PUINT8 GetRow(int row);
		// * returns the color index of pixel (x, y) starting from top left
		_H3API_ PUINT8 GetPixelIndex(int x, int y);
		// * fills rectangle with color index from palette565
		_H3API_ VOID FillRectangle(INT x, INT y, INT dx, INT dy, BYTE color_index);

		_H3API_ H3LoadedPcx(LPCSTR name);
		_H3API_ VOID Init(LPCSTR name);
		_H3API_ VOID Init(LPCSTR name, INT w, INT h);

		_H3API_ static H3LoadedPcx* Load(LPCSTR name);
		_H3API_ static H3LoadedPcx* Create(LPCSTR name, INT width, INT height);
	};
	_H3API_ASSERT_SIZE_(H3LoadedPcx, 0x56C);

	struct H3LoadedPcx16 : public H3ResourceItem // size 0x38 // vt 63B9C8
	{
		// * +1C
		INT32 buffSize;
	protected:
		// * +20
		INT32 buffSizeUnk;
	public:
		// * +24
		INT32 width;
		// * +28
		INT32 height;
		// * +2C
		INT32 scanlineSize;
		// * +30
		// * H3RGB565 buffer unless bitmode == 4
		// * in which case this is a H3ARGB888 buffer
		PUINT8 buffer;
		BOOL8 keepBuffer; // see 0x44DDE0

		_H3API_ VOID CopyRegion(H3LoadedPcx16* source, INT x, INT y);
		_H3API_ H3LoadedPcx16* Construct(LPCSTR name, INT width, INT height);
		_H3API_ VOID DrawToPcx16(INT x, INT y, BOOL transparent, H3LoadedPcx16* dest, INT srcX = 0, INT srcY = 0);
		_H3API_ VOID Destroy(BOOL destroy_buffer = TRUE);
		// * darkens RGB by about 50%
		_H3API_ VOID DrawShadow(INT x, INT y, INT dw, INT dh);
		_H3API_ VOID FillRectangle(INT x, INT y, INT w, INT h, BYTE r, BYTE g, BYTE b);
		_H3API_ VOID FillRectangle(INT x, INT y, INT w, INT h, DWORD color);
		_H3API_ VOID DrawFrame(INT x, INT y, INT w, INT h, BYTE r = 232, BYTE g = 212, BYTE b = 120);
		_H3API_ VOID DrawFrame(INT x, INT y, INT w, INT h, const H3RGB888& color);
		_H3API_ VOID DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, BYTE r, BYTE g, BYTE b);
		_H3API_ VOID DrawThickFrame(INT x, INT y, INT w, INT h, INT thickness, const H3RGB888& color);
		_H3API_ VOID DarkenArea(INT x, INT y, INT w, INT h, UINT8 amount);
		_H3API_ VOID LightenArea(INT x, INT y, INT w, INT h, UINT8 amount);
		_H3API_ VOID GrayScaleArea(INT x, INT y, INT w, INT h);
		// * modifies hue and saturation of region to match the specified values (HSV model)
		// * <hue> is on the scale 0~1 and represents the color scheme
		// * <saturation> is also scaled between 0 ~ 1 and represents how colorful (0 being grayscale) the image appears
		// * value is fixed
		_H3API_ VOID AdjustHueSaturation(INT x, INT y, INT w, INT h, FLOAT hue, FLOAT saturation);
		_H3API_ BOOL BackgroundRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL is_blue);
		_H3API_ BOOL SimpleFrameRegion(INT32 x, INT32 y, INT32 _width, INT32 _height);
		_H3API_ BOOL FrameRegion(INT32 x, INT32 y, INT32 w, INT32 h, BOOL statusBar, INT32 colorIndex, BOOL is_blue);
		// * adds a 1 pixel border around the designated area to make it look
		// * as if the contents were lowered
		_H3API_ VOID SinkArea(INT32 x, INT32 y, INT32 w, INT32 h);
		// * adds a 1 pixel border around the designated area to make it look
		// * as if the contents were elevated
		_H3API_ VOID BevelArea(INT32 x, INT32 y, INT32 w, INT32 h);
		// * Draws text on the pcx
		_H3API_ VOID TextDraw(H3Font* font, LPCSTR text, INT32 x, INT32 y, INT32 width, INT32 height,
			NH3Dlg::TextColor::eTextColor colorIndex = NH3Dlg::TextColor::REGULAR,
			NH3Dlg::TextAlignment::eTextAlignment alignment = NH3Dlg::TextAlignment::MIDDLE_CENTER);

		_H3API_ static H3LoadedPcx16* Load(LPCSTR name);
		_H3API_ static H3LoadedPcx16* Create(LPCSTR name, INT width, INT height);
	protected:
		// * returns row start in buffer
		_H3API_ PUINT8 GetRow(int row);
		// * returns rgb565 pixel at coordinates (x,y) in buffer
		// * !WARNING! This is only valid when h3_BitMode == 2 aka default
		_H3API_ H3RGB565* GetPixel565(int x, int y);
		// * returns rgb565 pixel at coordinates (x,y) in buffer
		// * !WARNING! This is only valid when h3_BitMode == 4 aka TRUE mode with HDmod
		_H3API_ H3ARGB888* GetPixel888(int x, int y);
		_H3API_ H3ARGB888 GetPixel(int x, int y);
	};
	_H3API_ASSERT_SIZE_(H3LoadedPcx16, 0x38);

	struct H3LoadedPcx24 : public H3ResourceItem // size 0x30 // vt 63B9F4
	{
		// * +1C
		INT32 buffSize;
	protected:
		// * +20
		INT32 buffSizeUnk;
	public:
		// * +24
		INT32 width;
		// * +28
		INT32 height;
		// * +2C
		// * RGB888 buffer
		PUINT8 buffer;

		// * data argument can be NULL if needed, in this case no pixels will be copied
		// * you should still set dataSize as that is sent to buffSize
		// * dataSize = width * height * 3
		_H3API_ H3LoadedPcx24* Construct(LPCSTR name, INT width, INT height, PUINT8 data, UINT32 dataSize);
		// * converts RGB888 to RGB565
		// * if True mode, copies to ARGB888
		_H3API_ VOID DrawToPcx16(INT dst_x, INT dst_y, H3LoadedPcx16* dest, INT srcX = 0, INT srcY = 0);
		// * returns row start in buffer
		_H3API_ PUINT8 GetRow(int row);
		// * returns rgb888 pixel at coordinates (x, y) in buffer
		_H3API_ H3RGB888* GetPixel(int x, int y);

		_H3API_ static H3LoadedPcx24* Load(LPCSTR name, INT width, INT height);
	};
	_H3API_ASSERT_SIZE_(H3LoadedPcx24, 0x30);

	struct H3DefFrame : public H3ResourceItem
	{
		// * +1C
		// * all row offsets and actual pixel data
		INT32 rawDataSize;
		// * +20
		// * frame width * frame height
		INT32 dataSize;
		// * +24
		INT32 compressionType;
		// * +28
		INT32 width;
		// * +2C
		INT32 height;
		// * +30
		INT32 frameWidth;
		// * +34
		INT32 frameHeight;
		// * +38
		// * marginLeft + frameWidth = width
		INT32 marginLeft;
		// * +3C
		INT32 marginTop;
		// * +40
		INT32 width2;
		// * +44
		// * pixel index and such.
		PUINT8 rawData;

		_H3API_ VOID DrawToPcx16(INT src_x, INT src_y, INT src_width, INT src_height, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y,
			H3Palette565* palette565, BOOL mirror = FALSE, BOOL do_not_use_special_colors = TRUE);
	};
	_H3API_ASSERT_SIZE_(H3DefFrame, 0x48);

	// * Not a binary item but relevant to H3LoadedDef and H3DefFrame
	struct H3DefGroup
	{
		// * +0
		INT32 count;
		// * +4
		UINT32 spritesSize;
		// * +8
		H3DefFrame** frames;

		_H3API_ H3DefFrame& operator[](UINT index);
	};
	_H3API_ASSERT_SIZE_(H3DefGroup, 0x0C);

	struct H3LoadedDef : public H3ResourceItem
	{
		// * +1C
		H3DefGroup** groups;
		// * +20
		H3Palette565* palette565;
		// * +24
		H3Palette888* palette888;
		// * +28
		INT32 groupsCount;
		// * +2C
		INT32* activeGroups;
		// * +30
		INT32 widthDEF;
		// * +34
		INT32 heightDEF;

		// * for creature animation groups
		enum eCreatureGroups
		{
			CG_MOVING                = 0,
			CG_MOUSE_OVER            = 1,
			CG_STANDING              = 2,
			CG_GETTING_HIT           = 3,
			CG_DEFEND                = 4,
			CG_DEATH                 = 5,
			CG_UNUSED_DEATH          = 6,
			CG_TURN_LEFT             = 7,
			CG_TURN_RIGHT            = 8,
			CG_TURN_LEFT2            = 9,
			CG_TURN_RIGHT2           = 10,
			CG_ATTACK_UP             = 11,
			CG_ATTACK_STRAIGHT       = 12,
			CG_ATTACK_DOWN           = 13,
			CG_SHOOT_UP              = 14,
			CG_SHOOT_STRAIGHT        = 15,
			CG_SHOOT_DOWN            = 16,
			CG_SPELL_ATTACK_UP       = 17,
			CG_SPELL_ATTACK_STRAIGHT = 18,
			CG_SPELL_ATTACK_DOWN     = 19,
			CG_START_MOVING          = 20,
			CG_STOP_MOVING           = 21
		};

		_H3API_ VOID AddFrameFromDef(LPCSTR source, INT32 index);
		_H3API_ VOID ColorToPlayer(INT32 id);
		_H3API_ H3DefFrame* GetGroupFrame(INT group, INT frame);
		_H3API_ VOID DrawTransparent(INT32 frame, H3LoadedPcx16* pcx, INT32 x, INT32 y, BOOL transparent = TRUE,
			BOOL mirror = FALSE, INT32 group = 0, INT32 xFromRight = 0, INT32 yFromBottom = 0);
		_H3API_ VOID DrawToPcx16(INT group, INT frame, INT src_x, INT src_y, INT src_width, INT src_height,
			H3LoadedPcx16* pcx16, INT dst_x, INT dst_y, BOOL mirror = FALSE, BOOL do_not_use_special_colors = TRUE);
		_H3API_ VOID DrawToPcx16(INT group, INT frame, H3LoadedPcx16* pcx16, INT dst_x, INT dst_y);

		_H3API_ VOID AddDefGroup(UINT group_id, UINT frames_in_group);
		_H3API_ VOID AddFrameToGroup(UINT group_id, H3DefFrame* frame);
		_H3API_ VOID Init(LPCSTR name, UINT type, UINT width, UINT height);

		_H3API_ H3DefGroup& operator[](UINT index);

		_H3API_ static H3LoadedDef* Load(LPCSTR name);
	};
	_H3API_ASSERT_SIZE_(H3LoadedDef, 0x38);
#pragma pack(pop)

	// * a raii loader for h3 resources
	template <typename T>
	class H3BinaryLoader
	{
	protected:
		T* m_binary;
	public:
		inline H3BinaryLoader();
		inline H3BinaryLoader(T* binary_item);
		inline ~H3BinaryLoader();
		void Set(T* binary);
		T*   Get();
		T*   Release();
		T*   operator->();
		T*   operator*();
		BOOL operator!();
		operator BOOL();
	};

	class H3DefLoader : public H3BinaryLoader<H3LoadedDef>
	{
	public:
		H3DefLoader(H3LoadedDef* def);
		inline H3DefLoader(LPCSTR name);
	};
	class H3PcxLoader : public H3BinaryLoader<H3LoadedPcx>
	{
	public:
		inline H3PcxLoader(LPCSTR name);
	};
	class H3Pcx16Loader : public H3BinaryLoader<H3LoadedPcx16>
	{
	public:
		inline H3Pcx16Loader(LPCSTR name);
	};
	class H3FontLoader : public H3BinaryLoader<H3Font>
	{
	public:
		inline H3FontLoader(LPCSTR name);
	};
	class H3TextFileLoader : public H3BinaryLoader<H3TextFile>
	{
	public:
		inline H3TextFileLoader(LPCSTR name);
	};
	class H3TextTableLoader : public H3BinaryLoader<H3TextTable>
	{
	public:
		inline H3TextTableLoader(LPCSTR name);
	};
	class H3WavLoader : public H3BinaryLoader<H3WavFile>
	{
	public:
		inline H3WavLoader(LPCSTR name);
	};

	namespace H3Internal
	{
		_H3API_ H3RGB565 _RGB565Mask50();
		_H3API_ H3RGB565 _RGB565Mask25();
	}
}

#endif /* #define _H3BINARYITEMS_HPP_ */
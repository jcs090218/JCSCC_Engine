/**
 * $File: Camera2D.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Camera2D.h"


namespace JCS_D3DX_v11_Engine
{
	Camera2D::Camera2D()
		: m_smoothEffect(true)
		, m_pTargetTranform(nullptr)
		, m_friction(12.0f)
		, m_transform()
	{

	}

	Camera2D::~Camera2D()
	{

	}

	void Camera2D::Update(float32 deltaTime)
	{
		SmoothEffect(deltaTime);
	}

	void Camera2D::SmoothEffect(float32 deltaTime)
	{
		if (!m_smoothEffect)
			return;

		if (!m_pTargetTranform)
			return;

		// 現在值 += (目標值 - 現在值 ) / 漸進係數(或稱磨擦力)
		m_transform.position.x += (m_pTargetTranform->position.x - m_transform.position.x) / m_friction;
		m_transform.position.y += (m_pTargetTranform->position.y - m_transform.position.y) / m_friction;
	}

}

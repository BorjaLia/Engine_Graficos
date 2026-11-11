#include "Material.h"

namespace engine
{
	Material::Material(const std::string& vertexPath, const std::string& fragmentPath)
		: m_Texture(nullptr)
	{
		m_Shader = new Shader(vertexPath, fragmentPath);
		m_Tint = utils::Color::blue();
	}

	Material::~Material()
	{
		delete m_Shader;
		//m_Texture should be handled by a Resource Manager.
	}

	void Material::SetTexture(Texture* texture)
	{
		m_Texture = texture;
	}

	void Material::SetTint(utils::Color color)
	{
		m_Tint = color;
	}

	Shader* Material::GetShader() const
	{
		return m_Shader;
	}

	void Material::Bind() const
	{
		m_Shader->Bind();

		if (m_Texture)
		{
			m_Texture->Bind(0);
			m_Shader->SetUniform("u_texture", 0);
		}
		m_Shader->SetUniform("u_Color", math::Vector4(m_Tint.r, m_Tint.g, m_Tint.b, m_Tint.a));
	}

	void Material::Unbind() const
	{
		m_Shader->Unbind();
		if (m_Texture) m_Texture->Unbind(); 
	}
}
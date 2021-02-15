#ifndef __BLOOMBUFFER_H__
#define __BLOOMBUFFER_H__

#include "PostEffect.h"

//Taken from SpriteLab3 (Nick Juniper) and modified to fit
class BloomEffect : public PostEffect
{
public:
	//Initializes the framebuffer with extra steps
	//*Sets size
	//*Initializes the framebuffer afterwards
	void Init(unsigned width, unsigned height) override;

	//Applies the affect to this screen
	//*Passes the framebuffer with the texture to apply as a parameter
	void ApplyEffect(PostEffect* buffer) override;

	//Reshapes the buffers
	void Reshape(unsigned width, unsigned height) override;

	//Getters
	float GetDownscale() const;
	float GetThreshold() const;
	unsigned GetPasses() const;

	//Setters
	void SetDownscale(float downscale);
	void SetThreshold(float threshold);
	void SetPasses(unsigned passes);

private:
	float m_downscale = 2.f;
	float m_threshold = 0.01f;
	unsigned m_passes = 10;
	glm::vec2 m_pixelSize;
};

#endif // !__BLOOMBUFFER_H__
// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include "SBiquadIIFilterBank.h"
#include <AK/SoundEngine/Common/IAkMixerPlugin.h>
#include <AK/SoundEngine/Common/IAkPluginMemAlloc.h>
#include <memory>

namespace CryAudio
{
namespace Impl
{
namespace Wwise
{
namespace Plugins
{
enum class EVoiceType
{
	None,
	IsSpatialized,
	NotSpatialized,
};

enum class ESourceDirection
{
	None,
	Left,
	Right,
};

struct SAkUserData final
{
	explicit SAkUserData()
		: pVoiceDelayBuffer()
		, voiceDelayPrev(0)
		, voiceCycleDominantEQ(0)
		, voiceCycleDominantDelay(0)
		, lastVolumeDirect(1.0f)
		, lastVolumeConcealed(1.0f)
		, inputType(EVoiceType::None)
		, lastSourceDirection(ESourceDirection::None)
	{
	}

	~SAkUserData()
	{
		delete filterBankA;
		delete filterBankB;
	}

	std::unique_ptr<AkAudioBuffer> pVoiceDelayBuffer;

	int                            voiceDelayPrev;
	int                            voiceCycleDominantEQ;
	int                            voiceCycleDominantDelay;

	AkReal32                       lastVolumeDirect;
	AkReal32                       lastVolumeConcealed;

	EVoiceType                     inputType;
	ESourceDirection               lastSourceDirection;

	SBiquadIIFilterBank*           filterBankA;
	SBiquadIIFilterBank*           filterBankB;
};
} // namespace Plugins
} // namespace Wwise
} // namespace Impl
} // namespace CryAudio
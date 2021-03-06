/*
 * Copyright (C) 2017 Incognito
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MANIPULATION_H
#define MANIPULATION_H

#include "common.h"

namespace Manipulation
{
	enum
	{
		AreaID,
		AttachedObject,
		AttachedPlayer,
		AttachedVehicle,
		AttachOffsetX,
		AttachOffsetY,
		AttachOffsetZ,
		AttachRX,
		AttachRY,
		AttachRZ,
		AttachX,
		AttachY,
		AttachZ,
		Color,
		Color2,
		DrawDistance,
		ExtraID,
		Health,
		InteriorID,
		Invulnerable,
		MaxX,
		MaxY,
		MaxZ,
		MinX,
		MinY,
		MinZ,
		ModelID,
		MoveRX,
		MoveRY,
		MoveRZ,
		MoveSpeed,
		MoveX,
		MoveY,
		MoveZ,
		NextX,
		NextY,
		NextZ,
		PaintJob,
		PlayerID,
		Priority,
		QuatW,
		QuatX,
		QuatY,
		QuatZ,
		RespawnTime,
		Rotation,
		RX,
		RY,
		RZ,
		Size,
		SpawnAngle,
		SpawnColor1,
		SpawnColor2,
		SpawnX,
		SpawnY,
		SpawnZ,
		Siren,
		StreamDistance,
		Style,
		SyncRotation,
		TestLOS,
		Type,
		WorldID,
		X,
		Y,
		Z
	};

	enum
	{
		InvalidData,
		InvalidID,
		InvalidType
	};
}

#include "manipulation/array.h"
#include "manipulation/float.h"
#include "manipulation/int.h"

#endif

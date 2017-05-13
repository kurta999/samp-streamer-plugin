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

#ifndef ITEM_H
#define ITEM_H

#include "cell.h"
#include "common.h"
#include "identifier.h"

#include <boost/chrono.hpp>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/variant.hpp>

#include <Eigen/Core>

#include <bitset>
#include <string>

namespace Item
{
	struct Actor
	{
		Actor();

		int actorID;
		AMX *amx;
		SharedCell cell;
		float comparableStreamDistance;
		float health;
		bool inverseAreaChecking;
		bool invulnerable;
		int modelID;
		float originalComparableStreamDistance;
		Eigen::Vector3f position;
		Eigen::Vector3f positionOffset;
		int priority;
		int references;
		float rotation;
		float streamDistance;
		int worldID;

		struct Anim
		{
			Anim();

			float delta;
			bool freeze;
			std::string lib;
			bool loop;
			bool lockx;
			bool locky;
			std::string name;
			int references;
			int time;
		};

		boost::intrusive_ptr<Anim> anim;

		boost::unordered_set<int> areas;
		std::vector<int> extras;
		boost::unordered_set<int> interiors;
		std::bitset<MAX_PLAYERS> players;
		boost::unordered_set<int> worlds;

		static Identifier identifier;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	};

	struct Area
	{
		Area();

		AMX *amx;
		int areaID;
		SharedCell cell;
		float comparableSize;
		Eigen::Vector2f height;
		int priority;
		int references;
		float size;
		bool spectateMode;
		int type;

		boost::variant<Polygon2D, Box2D, Box3D, Eigen::Vector2f, Eigen::Vector3f> position;

		struct Attach
		{
			Attach();

			Eigen::Vector2f height;
			boost::tuple<int, int, int> object;
			int player;
			boost::variant<Polygon2D, Box2D, Box3D, Eigen::Vector2f, Eigen::Vector3f> position;
			Eigen::Vector3f positionOffset;
			int references;
			int vehicle;
			int vehicleType;

			EIGEN_MAKE_ALIGNED_OPERATOR_NEW
		};

		boost::intrusive_ptr<Attach> attach;

		boost::unordered_set<int> areas;
		std::vector<int> extras;
		boost::unordered_set<int> interiors;
		std::bitset<MAX_PLAYERS> players;
		boost::unordered_set<int> worlds;

		static Identifier identifier;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	};

	struct Checkpoint
	{
		Checkpoint();

		AMX *amx;
		SharedCell cell;
		int checkpointID;
		float comparableStreamDistance;
		bool inverseAreaChecking;
		float originalComparableStreamDistance;
		Eigen::Vector3f position;
		Eigen::Vector3f positionOffset;
		int priority;
		int references;
		float size;
		bool streamCallbacks;
		float streamDistance;

		boost::unordered_set<int> areas;
		std::vector<int> extras;
		boost::unordered_set<int> interiors;
		std::bitset<MAX_PLAYERS> players;
		boost::unordered_set<int> worlds;

		static Identifier identifier;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	};

	struct MapIcon
	{
		MapIcon();

		AMX *amx;
		SharedCell cell;
		int color;
		float comparableStreamDistance;
		bool inverseAreaChecking;
		int mapIconID;
		float originalComparableStreamDistance;
		Eigen::Vector3f position;
		Eigen::Vector3f positionOffset;
		int priority;
		int references;
		bool streamCallbacks;
		float streamDistance;
		int style;
		int type;

		boost::unordered_set<int> areas;
		std::vector<int> extras;
		boost::unordered_set<int> interiors;
		std::bitset<MAX_PLAYERS> players;
		boost::unordered_set<int> worlds;

		static Identifier identifier;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	};

	struct Object
	{
		Object();

		AMX *amx;
		SharedCell cell;
		float comparableStreamDistance;
		float drawDistance;
		bool inverseAreaChecking;
		int modelID;
		bool noCameraCollision;
		int objectID;
		float originalComparableStreamDistance;
		Eigen::Vector3f position;
		Eigen::Vector3f positionOffset;
		int priority;
		int references;
		Eigen::Vector3f rotation;
		bool streamCallbacks;
		float streamDistance;

		struct Attach
		{
			Attach();

			int object;
			int player;
			Eigen::Vector3f position;
			Eigen::Vector3f positionOffset;
			int references;
			Eigen::Vector3f rotation;
			bool syncRotation;
			int vehicle;
			int vehicleType;

			EIGEN_MAKE_ALIGNED_OPERATOR_NEW
		};

		boost::intrusive_ptr<Attach> attach;

		struct Material
		{
			struct Main
			{
				Main();

				int materialColor;
				int modelID;
				int references;
				std::string textureName;
				std::string txdFileName;
			};

			boost::intrusive_ptr<Main> main;

			struct Text
			{
				Text();

				int backColor;
				bool bold;
				int fontColor;
				std::string fontFace;
				int fontSize;
				int references;
				int materialSize;
				std::string materialText;
				int textAlignment;
			};

			boost::intrusive_ptr<Text> text;
		};

		boost::unordered_map<int, Material> materials;

		struct Move
		{
			Move();

			int duration;
			boost::tuple<Eigen::Vector3f, Eigen::Vector3f, Eigen::Vector3f> position;
			int references;
			boost::tuple<Eigen::Vector3f, Eigen::Vector3f, Eigen::Vector3f> rotation;
			float speed;
			boost::chrono::steady_clock::time_point time;

			EIGEN_MAKE_ALIGNED_OPERATOR_NEW
		};

		boost::intrusive_ptr<Move> move;

		boost::unordered_set<int> areas;
		std::vector<int> extras;
		boost::unordered_set<int> interiors;
		std::bitset<MAX_PLAYERS> players;
		boost::unordered_set<int> worlds;

		static Identifier identifier;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	};

	struct Pickup
	{
		Pickup();

		AMX *amx;
		SharedCell cell;
		float comparableStreamDistance;
		bool inverseAreaChecking;
		int modelID;
		float originalComparableStreamDistance;
		int pickupID;
		Eigen::Vector3f position;
		Eigen::Vector3f positionOffset;
		int priority;
		int references;
		bool streamCallbacks;
		float streamDistance;
		int type;
		int worldID;

		boost::unordered_set<int> areas;
		std::vector<int> extras;
		boost::unordered_set<int> interiors;
		std::bitset<MAX_PLAYERS> players;
		boost::unordered_set<int> worlds;

		static Identifier identifier;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	};

	struct RaceCheckpoint
	{
		RaceCheckpoint();

		AMX *amx;
		SharedCell cell;
		float comparableStreamDistance;
		bool inverseAreaChecking;
		Eigen::Vector3f next;
		float originalComparableStreamDistance;
		Eigen::Vector3f position;
		Eigen::Vector3f positionOffset;
		int priority;
		int raceCheckpointID;
		int references;
		float size;
		bool streamCallbacks;
		float streamDistance;
		int type;

		boost::unordered_set<int> areas;
		std::vector<int> extras;
		boost::unordered_set<int> interiors;
		std::bitset<MAX_PLAYERS> players;
		boost::unordered_set<int> worlds;

		static Identifier identifier;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	};

	struct TextLabel
	{
		TextLabel();

		AMX *amx;
		SharedCell cell;
		int color;
		float comparableStreamDistance;
		float drawDistance;
		bool inverseAreaChecking;
		float originalComparableStreamDistance;
		Eigen::Vector3f position;
		Eigen::Vector3f positionOffset;
		int priority;
		int references;
		bool streamCallbacks;
		float streamDistance;
		bool testLOS;
		std::string text;
		int textLabelID;

		struct Attach
		{
			Attach();

			int player;
			Eigen::Vector3f position;
			int references;
			int vehicle;
			int vehicleType;
		};

		boost::intrusive_ptr<Attach> attach;

		boost::unordered_set<int> areas;
		std::vector<int> extras;
		boost::unordered_set<int> interiors;
		std::bitset<MAX_PLAYERS> players;
		boost::unordered_set<int> worlds;

		static Identifier identifier;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	};

	struct Vehicle
	{
		Vehicle();

		AMX *amx;
		SharedCell cell;
		float comparableStreamDistance;
		bool inverseAreaChecking;
		float originalComparableStreamDistance;
		int modelID;
		Eigen::Vector3f position;
		Eigen::Vector3f positionOffset;
		//float qw, qx, qy, qz;
		Eigen::Vector4f quat;
		float angle;
		boost::array<int, 2> color;
		int respawnDelay;
		int paintjob;
		int interior;
		int worldID;
		float health;
		std::vector<int> carmods;
		std::string numberplate;
		int panels;
		int doors;
		int lights;
		int tires;

		struct Spawn
		{
			Eigen::Vector3f position;
			float angle;
			boost::array<int, 2> color;
			bool addsiren;
		} spawn;

		struct Params
		{
			char engine, lights, alarm, doors, bonnet, boot, objective;
			char siren;
			struct Doors
			{
				char driver, passenger, backleft, backright;
			} cardoors;
			struct Windows
			{
				char driver, passenger, backleft, backright;
			} carwindows;
		} params;

		int references;
		int priority;
		bool streamCallbacks;
		float streamDistance;
		int vehicleID;
		bool touched;
		bool used;
		boost::chrono::steady_clock::time_point spawnedTime;
		boost::chrono::steady_clock::time_point lastUpdatedTime;

		boost::unordered_set<int> areas;
		std::vector<int> extras;
		boost::unordered_set<int> interiors;
		std::bitset<MAX_PLAYERS> players;
		boost::unordered_set<int> worlds;

		static Identifier identifier;

		EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	};
}

#endif

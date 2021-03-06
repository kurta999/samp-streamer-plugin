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

#include "int.h"

#include "../core.h"
#include "../utility.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/variant.hpp>

#include <Eigen/Core>

#include <bitset>
#include <cmath>

int Manipulation::getIntData(AMX *amx, cell *params)
{
	int error = -1;
	switch (static_cast<int>(params[1]))
	{
		case STREAMER_TYPE_OBJECT:
		{
			boost::unordered_map<int, Item::SharedObject>::iterator o = core->getData()->objects.find(static_cast<int>(params[2]));
			if (o != core->getData()->objects.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::getFirstValueInContainer(o->second->areas);
					}
					case AttachedObject:
					{
						if (o->second->attach)
						{
							return o->second->attach->object;
						}
						return INVALID_STREAMER_ID;
					}
					case AttachedPlayer:
					{
						if (o->second->attach)
						{
							return o->second->attach->player;
						}
						return INVALID_GENERIC_ID;
					}
					case AttachedVehicle:
					{
						if (o->second->attach)
						{
							return o->second->attach->vehicle;
						}
						return INVALID_GENERIC_ID;
					}
					case ExtraID:
					{
						return Utility::getFirstValueInContainer(o->second->extras);
					}
					case InteriorID:
					{
						return Utility::getFirstValueInContainer(o->second->interiors);
					}
					case ModelID:
					{
						return o->second->modelID;
					}
					case PlayerID:
					{
						return Utility::getFirstValueInContainer(o->second->players);
					}
					case Priority:
					{
						return o->second->priority;
					}
					case SyncRotation:
					{
						if (o->second->attach)
						{
							if (o->second->attach->object != INVALID_STREAMER_ID)
							{
								return o->second->attach->syncRotation != 0;
							}
						}
						return 0;
					}
					case WorldID:
					{
						return Utility::getFirstValueInContainer(o->second->worlds);
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_PICKUP:
		{
			boost::unordered_map<int, Item::SharedPickup>::iterator p = core->getData()->pickups.find(static_cast<int>(params[2]));
			if (p != core->getData()->pickups.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::getFirstValueInContainer(p->second->areas);
					}
					case ExtraID:
					{
						return Utility::getFirstValueInContainer(p->second->extras);
					}
					case InteriorID:
					{
						return Utility::getFirstValueInContainer(p->second->interiors);
					}
					case ModelID:
					{
						return p->second->modelID;
					}
					case PlayerID:
					{
						return Utility::getFirstValueInContainer(p->second->players);
					}
					case Priority:
					{
						return p->second->priority;
					}
					case Type:
					{
						return p->second->type;
					}
					case WorldID:
					{
						return Utility::getFirstValueInContainer(p->second->worlds);
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_CP:
		{
			boost::unordered_map<int, Item::SharedCheckpoint>::iterator c = core->getData()->checkpoints.find(static_cast<int>(params[2]));
			if (c != core->getData()->checkpoints.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::getFirstValueInContainer(c->second->areas);
					}
					case ExtraID:
					{
						return Utility::getFirstValueInContainer(c->second->extras);
					}
					case InteriorID:
					{
						return Utility::getFirstValueInContainer(c->second->interiors);
					}
					case PlayerID:
					{
						return Utility::getFirstValueInContainer(c->second->players);
					}
					case Priority:
					{
						return c->second->priority;
					}
					case WorldID:
					{
						return Utility::getFirstValueInContainer(c->second->worlds);
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_RACE_CP:
		{
			boost::unordered_map<int, Item::SharedRaceCheckpoint>::iterator r = core->getData()->raceCheckpoints.find(static_cast<int>(params[2]));
			if (r != core->getData()->raceCheckpoints.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::getFirstValueInContainer(r->second->areas);
					}
					case ExtraID:
					{
						return Utility::getFirstValueInContainer(r->second->extras);
					}
					case InteriorID:
					{
						return Utility::getFirstValueInContainer(r->second->interiors);
					}
					case PlayerID:
					{
						return Utility::getFirstValueInContainer(r->second->players);
					}
					case Priority:
					{
						return r->second->priority;
					}
					case Type:
					{
						return r->second->type;
					}
					case WorldID:
					{
						return Utility::getFirstValueInContainer(r->second->worlds);
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_MAP_ICON:
		{
			boost::unordered_map<int, Item::SharedMapIcon>::iterator m = core->getData()->mapIcons.find(static_cast<int>(params[2]));
			if (m != core->getData()->mapIcons.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::getFirstValueInContainer(m->second->areas);
					}
					case Color:
					{
						return m->second->color;
					}
					case ExtraID:
					{
						return Utility::getFirstValueInContainer(m->second->extras);
					}
					case InteriorID:
					{
						return Utility::getFirstValueInContainer(m->second->interiors);
					}
					case PlayerID:
					{
						return Utility::getFirstValueInContainer(m->second->players);
					}
					case Priority:
					{
						return m->second->priority;
					}
					case Style:
					{
						return m->second->style;
					}
					case Type:
					{
						return m->second->type;
					}
					case WorldID:
					{
						return Utility::getFirstValueInContainer(m->second->worlds);
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_3D_TEXT_LABEL:
		{
			boost::unordered_map<int, Item::SharedTextLabel>::iterator t = core->getData()->textLabels.find(static_cast<int>(params[2]));
			if (t != core->getData()->textLabels.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::getFirstValueInContainer(t->second->areas);
					}
					case AttachedPlayer:
					{
						if (t->second->attach)
						{
							return t->second->attach->player;
						}
						return INVALID_GENERIC_ID;
					}
					case AttachedVehicle:
					{
						if (t->second->attach)
						{
							return t->second->attach->vehicle;
						}
						return INVALID_GENERIC_ID;
					}
					case Color:
					{
						return t->second->color;
					}
					case ExtraID:
					{
						return Utility::getFirstValueInContainer(t->second->extras);
					}
					case InteriorID:
					{
						return Utility::getFirstValueInContainer(t->second->interiors);
					}
					case PlayerID:
					{
						return Utility::getFirstValueInContainer(t->second->players);
					}
					case Priority:
					{
						return t->second->priority;
					}
					case TestLOS:
					{
						return t->second->testLOS;
					}
					case WorldID:
					{
						return Utility::getFirstValueInContainer(t->second->worlds);
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_AREA:
		{
			boost::unordered_map<int, Item::SharedArea>::iterator a = core->getData()->areas.find(static_cast<int>(params[2]));
			if (a != core->getData()->areas.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AttachedObject:
					{
						if (a->second->attach)
						{
							return a->second->attach->object.get<0>();
						}
						return INVALID_STREAMER_ID;
					}
					case AttachedPlayer:
					{
						if (a->second->attach)
						{
							return a->second->attach->player;
						}
						return INVALID_GENERIC_ID;
					}
					case AttachedVehicle:
					{
						if (a->second->attach)
						{
							return a->second->attach->vehicle;
						}
						return INVALID_GENERIC_ID;
					}
					case ExtraID:
					{
						return Utility::getFirstValueInContainer(a->second->extras);
					}
					case InteriorID:
					{
						return Utility::getFirstValueInContainer(a->second->interiors);
					}
					case PlayerID:
					{
						return Utility::getFirstValueInContainer(a->second->players);
					}
					case Priority:
					{
						return a->second->priority;
					}
					case Type:
					{
						return a->second->type;
					}
					case WorldID:
					{
						return Utility::getFirstValueInContainer(a->second->worlds);
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_ACTOR:
		{
			boost::unordered_map<int, Item::SharedActor>::iterator a = core->getData()->actors.find(static_cast<int>(params[2]));
			if (a != core->getData()->actors.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::getFirstValueInContainer(a->second->areas);
					}
					case ExtraID:
					{
						return Utility::getFirstValueInContainer(a->second->extras);
					}
					case InteriorID:
					{
						return Utility::getFirstValueInContainer(a->second->interiors);
					}
					case Invulnerable:
					{
						return a->second->invulnerable;
					}
					case ModelID:
					{
						return a->second->modelID;
					}
					case PlayerID:
					{
						return Utility::getFirstValueInContainer(a->second->players);
					}
					case Priority:
					{
						return a->second->priority;
					}
					case WorldID:
					{
						return Utility::getFirstValueInContainer(a->second->worlds);
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_VEHICLE:
		{
			boost::unordered_map<int, Item::SharedVehicle>::iterator v = core->getData()->vehicles.find(static_cast<int>(params[2]));
			if (v != core->getData()->vehicles.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::getFirstValueInContainer(v->second->areas);
					}
					case ExtraID:
					{
						return Utility::getFirstValueInContainer(v->second->extras);
					}
					case InteriorID:
					{
						return Utility::getFirstValueInContainer(v->second->interiors);
					}
					case ModelID:
					{
						return v->second->modelID;
					}
					case RespawnTime:
					{
						return v->second->respawnDelay;
					}
					case PaintJob:
					{
						return v->second->paintjob;
					}
					case PlayerID:
					{
						return Utility::getFirstValueInContainer(v->second->players);
					}
					case Priority:
					{
						return v->second->priority;
					}
					case WorldID:
					{
						return Utility::getFirstValueInContainer(v->second->worlds);
					}

				}
			}
		}
		default:
		{
			error = InvalidType;
			break;
		}
	}
	switch (error)
	{
		case InvalidData:
		{
			Utility::logError("Streamer_GetIntData: Invalid data specified.");
			break;
		}
		case InvalidID:
		{
			Utility::logError("Streamer_GetIntData: Invalid ID specified.");
			break;
		}
		case InvalidType:
		{
			Utility::logError("Streamer_GetIntData: Invalid type specified.");
			break;
		}
	}
	return 0;
}

int Manipulation::setIntData(AMX *amx, cell *params)
{
	int error = -1;
	bool update = false;
	switch (static_cast<int>(params[1]))
	{
		case STREAMER_TYPE_OBJECT:
		{
			boost::unordered_map<int, Item::SharedObject>::iterator o = core->getData()->objects.find(static_cast<int>(params[2]));
			if (o != core->getData()->objects.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::setFirstValueInContainer(o->second->areas, static_cast<int>(params[4])) != 0;
					}
					case AttachedObject:
					{
						if (static_cast<int>(params[4]) != INVALID_STREAMER_ID)
						{
							if (o->second->move)
							{
								Utility::logError("Streamer_SetIntData: Object is currently moving and must be stopped first.");
								return 0;
							}
							if (sampgdk::FindNative("SetPlayerGravity") == NULL)
							{
								Utility::logError("Streamer_SetIntData: YSF plugin must be loaded to attach objects to objects.");
								return 0;
							}
							o->second->attach = boost::intrusive_ptr<Item::Object::Attach>(new Item::Object::Attach);
							o->second->attach->player = INVALID_GENERIC_ID;
							o->second->attach->vehicle = INVALID_GENERIC_ID;
							o->second->attach->object = static_cast<int>(params[4]);
							o->second->attach->positionOffset.setZero();
							o->second->attach->rotation.setZero();
							o->second->attach->syncRotation = true;
							core->getStreamer()->attachedObjects.insert(o->second);
							update = true;
						}
						else
						{
							if (o->second->attach)
							{
								if (o->second->attach->object != INVALID_STREAMER_ID)
								{
									o->second->attach.reset();
									core->getStreamer()->attachedObjects.erase(o->second);
									core->getGrid()->removeObject(o->second, true);
									update = true;
								}
							}
						}
						break;
					}
					case AttachedPlayer:
					{
						if (static_cast<int>(params[4]) != INVALID_GENERIC_ID)
						{
							if (o->second->move)
							{
								Utility::logError("Streamer_SetIntData: Object is currently moving and must be stopped first.");
								return 0;
							}
							if (sampgdk::FindNative("SetPlayerGravity") == NULL)
							{
								Utility::logError("Streamer_SetIntData: YSF plugin must be loaded to attach objects to players.");
								return 0;
							}
							o->second->attach = boost::intrusive_ptr<Item::Object::Attach>(new Item::Object::Attach);
							o->second->attach->object = INVALID_STREAMER_ID;
							o->second->attach->vehicle = INVALID_GENERIC_ID;
							o->second->attach->player = static_cast<int>(params[4]);
							o->second->attach->positionOffset.setZero();
							o->second->attach->rotation.setZero();
							core->getStreamer()->attachedObjects.insert(o->second);
							update = true;
						}
						else
						{
							if (o->second->attach)
							{
								if (o->second->attach->player != INVALID_GENERIC_ID)
								{
									o->second->attach.reset();
									core->getStreamer()->attachedObjects.erase(o->second);
									core->getGrid()->removeObject(o->second, true);
									update = true;
								}
							}
						}
						break;
					}
					case AttachedVehicle:
					{
						if (static_cast<int>(params[4]) != INVALID_GENERIC_ID)
						{
							if (o->second->move)
							{
								Utility::logError("Streamer_SetIntData: Object is currently moving and must be stopped first.");
								return 0;
							}
							o->second->attach = boost::intrusive_ptr<Item::Object::Attach>(new Item::Object::Attach);
							o->second->attach->object = INVALID_STREAMER_ID;
							o->second->attach->player = INVALID_GENERIC_ID;
							o->second->attach->vehicle = static_cast<int>(params[4]);
							o->second->attach->positionOffset.setZero();
							o->second->attach->rotation.setZero();
							core->getStreamer()->attachedObjects.insert(o->second);
							update = true;
						}
						else
						{
							if (o->second->attach)
							{
								if (o->second->attach->vehicle != INVALID_GENERIC_ID)
								{
									o->second->attach.reset();
									core->getStreamer()->attachedObjects.erase(o->second);
									core->getGrid()->removeObject(o->second, true);
									update = true;
								}
							}
						}
						break;
					}
					case ExtraID:
					{
						return Utility::setFirstValueInContainer(o->second->extras, static_cast<int>(params[4])) != 0;
					}
					case InteriorID:
					{
						return Utility::setFirstValueInContainer(o->second->interiors, static_cast<int>(params[4])) != 0;
					}
					case ModelID:
					{
						o->second->modelID = static_cast<int>(params[4]);
						update = true;
						break;
					}
					case PlayerID:
					{
						return Utility::setFirstValueInContainer(o->second->players, static_cast<int>(params[4])) != 0;
					}
					case Priority:
					{
						o->second->priority = static_cast<int>(params[4]);
						break;
					}
					case SyncRotation:
					{
						if (o->second->attach)
						{
							if (o->second->attach->object != INVALID_GENERIC_ID)
							{
								o->second->attach->syncRotation = static_cast<int>(params[4]) != 0;
								update = true;
							}
						}
						break;
					}
					case WorldID:
					{
						return Utility::setFirstValueInContainer(o->second->worlds, static_cast<int>(params[4])) != 0;
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
				if (update)
				{
					for (boost::unordered_map<int, Player>::iterator p = core->getData()->players.begin(); p != core->getData()->players.end(); ++p)
					{
						boost::unordered_map<int, int>::iterator i = p->second.internalObjects.find(o->first);
						if (i != p->second.internalObjects.end())
						{
							sampgdk::DestroyPlayerObject(p->first, i->second);
							i->second = sampgdk::CreatePlayerObject(p->first, o->second->modelID, o->second->position[0], o->second->position[1], o->second->position[2], o->second->rotation[0], o->second->rotation[1], o->second->rotation[2], o->second->drawDistance);
							if (o->second->attach)
							{
								if (o->second->attach->object != INVALID_STREAMER_ID)
								{
									boost::unordered_map<int, int>::iterator j = p->second.internalObjects.find(o->second->attach->object);
									if (j != p->second.internalObjects.end())
									{
										AMX_NATIVE native = sampgdk::FindNative("AttachPlayerObjectToObject");
										if (native != NULL)
										{
											sampgdk::InvokeNative(native, "dddffffffb", p->first, i->second, j->second, o->second->attach->positionOffset[0], o->second->attach->positionOffset[1], o->second->attach->positionOffset[2], o->second->attach->rotation[0], o->second->attach->rotation[1], o->second->attach->rotation[2], o->second->attach->syncRotation);
										}
									}
								}
								else if (o->second->attach->player != INVALID_GENERIC_ID)
								{
									AMX_NATIVE native = sampgdk::FindNative("AttachPlayerObjectToPlayer");
									if (native != NULL)
									{
										sampgdk::InvokeNative(native, "dddffffffd", p->first, i->second, o->second->attach->player, o->second->attach->positionOffset[0], o->second->attach->positionOffset[1], o->second->attach->positionOffset[2], o->second->attach->rotation[0], o->second->attach->rotation[1], o->second->attach->rotation[2], 1);
									}
								}
								else if (o->second->attach->vehicle != INVALID_GENERIC_ID)
								{
									sampgdk::AttachPlayerObjectToVehicle(p->first, i->second, o->second->attach->vehicle, o->second->attach->positionOffset[0], o->second->attach->positionOffset[1], o->second->attach->positionOffset[2], o->second->attach->rotation[0], o->second->attach->rotation[1], o->second->attach->rotation[2]);
								}
							}
							else if (o->second->move)
							{
								sampgdk::MovePlayerObject(p->first, i->second, o->second->move->position.get<0>()[0], o->second->move->position.get<0>()[1], o->second->move->position.get<0>()[2], o->second->move->speed, o->second->move->rotation.get<0>()[0], o->second->move->rotation.get<0>()[1], o->second->move->rotation.get<0>()[2]);
							}
							for (boost::unordered_map<int, Item::Object::Material>::iterator m = o->second->materials.begin(); m != o->second->materials.end(); ++m)
							{
								if (m->second.main)
								{
									sampgdk::SetPlayerObjectMaterial(p->first, i->second, m->first, m->second.main->modelID, m->second.main->txdFileName.c_str(), m->second.main->textureName.c_str(), m->second.main->materialColor);
								}
								else if (m->second.text)
								{
									sampgdk::SetPlayerObjectMaterialText(p->first, i->second, m->second.text->materialText.c_str(), m->first, m->second.text->materialSize, m->second.text->fontFace.c_str(), m->second.text->fontSize, m->second.text->bold, m->second.text->fontColor, m->second.text->backColor, m->second.text->textAlignment);
								}
							}
							if (o->second->noCameraCollision)
							{
								sampgdk::SetPlayerObjectNoCameraCol(p->first, i->second);
							}
						}
					}
				}
				return 1;
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_PICKUP:
		{
			boost::unordered_map<int, Item::SharedPickup>::iterator p = core->getData()->pickups.find(static_cast<int>(params[2]));
			if (p != core->getData()->pickups.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::setFirstValueInContainer(p->second->areas, static_cast<int>(params[4])) != 0;
					}
					case ExtraID:
					{
						return Utility::setFirstValueInContainer(p->second->extras, static_cast<int>(params[4])) != 0;
					}
					case InteriorID:
					{
						return Utility::setFirstValueInContainer(p->second->interiors, static_cast<int>(params[4])) != 0;
					}
					case ModelID:
					{
						p->second->modelID = static_cast<int>(params[4]);
						update = true;
						break;
					}
					case PlayerID:
					{
						return Utility::setFirstValueInContainer(p->second->players, static_cast<int>(params[4])) != 0;
					}
					case Priority:
					{
						p->second->priority = static_cast<int>(params[4]);
						return 1;
					}
					case Type:
					{
						p->second->type = static_cast<int>(params[4]);
						update = true;
						break;
					}
					case WorldID:
					{
						return Utility::setFirstValueInContainer(p->second->worlds, static_cast<int>(params[4])) != 0;
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
				if (update)
				{
					boost::unordered_map<int, int>::iterator i = core->getData()->internalPickups.find(p->first);
					if (i != core->getData()->internalPickups.end())
					{
						sampgdk::DestroyPickup(i->second);
						i->second = sampgdk::CreatePickup(p->second->modelID, p->second->type, p->second->position[0], p->second->position[1], p->second->position[2], p->second->worldID);
					}
				}
				return 1;
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_CP:
		{
			boost::unordered_map<int, Item::SharedCheckpoint>::iterator c = core->getData()->checkpoints.find(static_cast<int>(params[2]));
			if (c != core->getData()->checkpoints.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::setFirstValueInContainer(c->second->areas, static_cast<int>(params[4])) != 0;
					}
					case ExtraID:
					{
						return Utility::setFirstValueInContainer(c->second->extras, static_cast<int>(params[4])) != 0;
					}
					case InteriorID:
					{
						return Utility::setFirstValueInContainer(c->second->interiors, static_cast<int>(params[4])) != 0;
						update = true;
						break;
					}
					case PlayerID:
					{
						return Utility::setFirstValueInContainer(c->second->players, static_cast<int>(params[4])) != 0;
					}
					case Priority:
					{
						c->second->priority = static_cast<int>(params[4]);
						return 1;
					}
					case WorldID:
					{
						return Utility::setFirstValueInContainer(c->second->worlds, static_cast<int>(params[4])) != 0;
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_RACE_CP:
		{
			boost::unordered_map<int, Item::SharedRaceCheckpoint>::iterator r = core->getData()->raceCheckpoints.find(static_cast<int>(params[2]));
			if (r != core->getData()->raceCheckpoints.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::setFirstValueInContainer(r->second->areas, static_cast<int>(params[4])) != 0;
					}
					case ExtraID:
					{
						return Utility::setFirstValueInContainer(r->second->extras, static_cast<int>(params[4])) != 0;
					}
					case InteriorID:
					{
						return Utility::setFirstValueInContainer(r->second->interiors, static_cast<int>(params[4])) != 0;
					}
					case PlayerID:
					{
						return Utility::setFirstValueInContainer(r->second->players, static_cast<int>(params[4])) != 0;
					}
					case Priority:
					{
						r->second->priority = static_cast<int>(params[4]);
						return 1;
					}
					case Type:
					{
						r->second->type = static_cast<int>(params[4]);
						update = true;
						break;
					}
					case WorldID:
					{
						return Utility::setFirstValueInContainer(r->second->worlds, static_cast<int>(params[4])) != 0;
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
				if (update)
				{
					for (boost::unordered_map<int, Player>::iterator p = core->getData()->players.begin(); p != core->getData()->players.end(); ++p)
					{
						if (p->second.visibleRaceCheckpoint == r->first)
						{
							sampgdk::DisablePlayerRaceCheckpoint(p->first);
							p->second.delayedRaceCheckpoint = r->first;
						}
					}
				}
				return 1;
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_MAP_ICON:
		{
			boost::unordered_map<int, Item::SharedMapIcon>::iterator m = core->getData()->mapIcons.find(static_cast<int>(params[2]));
			if (m != core->getData()->mapIcons.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::setFirstValueInContainer(m->second->areas, static_cast<int>(params[4])) != 0;
					}
					case Color:
					{
						m->second->color = static_cast<int>(params[4]);
						update = true;
						break;
					}
					case ExtraID:
					{
						return Utility::setFirstValueInContainer(m->second->extras, static_cast<int>(params[4])) != 0;
					}
					case InteriorID:
					{
						return Utility::setFirstValueInContainer(m->second->interiors, static_cast<int>(params[4])) != 0;
					}
					case PlayerID:
					{
						return Utility::setFirstValueInContainer(m->second->players, static_cast<int>(params[4])) != 0;
					}
					case Priority:
					{
						m->second->priority = static_cast<int>(params[4]);
						return 1;
					}
					case Style:
					{
						m->second->style = static_cast<int>(params[4]);
						update = true;
						break;
					}
					case Type:
					{
						m->second->type = static_cast<int>(params[4]);
						update = true;
						break;
					}
					case WorldID:
					{
						return Utility::setFirstValueInContainer(m->second->worlds, static_cast<int>(params[4])) != 0;
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
				if (update)
				{
					for (boost::unordered_map<int, Player>::iterator p = core->getData()->players.begin(); p != core->getData()->players.end(); ++p)
					{
						boost::unordered_map<int, int>::iterator i = p->second.internalMapIcons.find(m->first);
						if (i != p->second.internalMapIcons.end())
						{
							sampgdk::RemovePlayerMapIcon(p->first, i->second);
							sampgdk::SetPlayerMapIcon(p->first, i->second, m->second->position[0], m->second->position[1], m->second->position[2], m->second->type, m->second->color, m->second->style);
						}
					}
				}
				return 1;
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_3D_TEXT_LABEL:
		{
			boost::unordered_map<int, Item::SharedTextLabel>::iterator t = core->getData()->textLabels.find(static_cast<int>(params[2]));
			if (t != core->getData()->textLabels.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::setFirstValueInContainer(t->second->areas, static_cast<int>(params[4])) != 0;
					}
					case AttachedPlayer:
					{
						if (static_cast<int>(params[4]) != INVALID_GENERIC_ID)
						{
							t->second->attach = boost::intrusive_ptr<Item::TextLabel::Attach>(new Item::TextLabel::Attach);
							t->second->attach->player = static_cast<int>(params[4]);
							t->second->attach->vehicle = INVALID_GENERIC_ID;
							core->getStreamer()->attachedTextLabels.insert(t->second);
							update = true;
						}
						else
						{
							if (t->second->attach)
							{
								if (t->second->attach->player != INVALID_GENERIC_ID)
								{
									t->second->attach.reset();
									core->getStreamer()->attachedTextLabels.erase(t->second);
									core->getGrid()->removeTextLabel(t->second, true);
									update = true;
								}
							}
						}
						break;
					}
					case AttachedVehicle:
					{
						if (static_cast<int>(params[4]) != INVALID_GENERIC_ID)
						{
							t->second->attach = boost::intrusive_ptr<Item::TextLabel::Attach>(new Item::TextLabel::Attach);
							t->second->attach->player = INVALID_GENERIC_ID;
							t->second->attach->vehicle = static_cast<int>(params[4]);
							core->getStreamer()->attachedTextLabels.insert(t->second);
							update = true;
						}
						else
						{
							if (t->second->attach)
							{
								if (t->second->attach->vehicle != INVALID_GENERIC_ID)
								{
									t->second->attach.reset();
									core->getStreamer()->attachedTextLabels.erase(t->second);
									core->getGrid()->removeTextLabel(t->second, true);
									update = true;
								}
							}
						}
						break;
					}
					case Color:
					{
						t->second->color = static_cast<int>(params[4]);
						update = true;
						break;
					}
					case ExtraID:
					{
						return Utility::setFirstValueInContainer(t->second->extras, static_cast<int>(params[4])) != 0;
					}
					case InteriorID:
					{
						return Utility::setFirstValueInContainer(t->second->interiors, static_cast<int>(params[4])) != 0;
					}
					case PlayerID:
					{
						return Utility::setFirstValueInContainer(t->second->players, static_cast<int>(params[4])) != 0;
					}
					case Priority:
					{
						t->second->priority = static_cast<int>(params[4]);
						return 1;
					}
					case TestLOS:
					{
						t->second->testLOS = static_cast<int>(params[4]) != 0;
						update = true;
						break;
					}
					case WorldID:
					{
						return Utility::setFirstValueInContainer(t->second->worlds, static_cast<int>(params[4])) != 0;
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
				if (update)
				{
					if (t->second->attach)
					{
						if (t->second->position.cwiseAbs().maxCoeff() > 50.0f)
						{
							t->second->position.setZero();
						}
					}
					for (boost::unordered_map<int, Player>::iterator p = core->getData()->players.begin(); p != core->getData()->players.end(); ++p)
					{
						boost::unordered_map<int, int>::iterator i = p->second.internalTextLabels.find(t->first);
						if (i != p->second.internalTextLabels.end())
						{
							sampgdk::DeletePlayer3DTextLabel(p->first, i->second);
							i->second = sampgdk::CreatePlayer3DTextLabel(p->first, t->second->text.c_str(), t->second->color, t->second->position[0], t->second->position[1], t->second->position[2], t->second->drawDistance, t->second->attach ? t->second->attach->player : INVALID_GENERIC_ID, t->second->attach ? t->second->attach->vehicle : INVALID_GENERIC_ID, t->second->testLOS);
						}
					}
				}
				return 1;
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_AREA:
		{
			boost::unordered_map<int, Item::SharedArea>::iterator a = core->getData()->areas.find(static_cast<int>(params[2]));
			if (a != core->getData()->areas.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AttachedObject:
					{
						Utility::logError("Streamer_SetIntData: Use AttachDynamicAreaToObject to adjust attached area data.");
						return 0;
					}
					case AttachedPlayer:
					{
						if (static_cast<int>(params[4]) != INVALID_GENERIC_ID)
						{
							a->second->attach = boost::intrusive_ptr<Item::Area::Attach>(new Item::Area::Attach);
							a->second->attach->object = boost::make_tuple(INVALID_STREAMER_ID, STREAMER_OBJECT_TYPE_DYNAMIC, INVALID_PLAYER_ID);
							a->second->attach->vehicle = INVALID_GENERIC_ID;
							a->second->attach->position = a->second->position;
							a->second->attach->player = static_cast<int>(params[4]);
							core->getStreamer()->attachedAreas.insert(a->second);
							return 1;
						}
						else
						{
							if (a->second->attach)
							{
								if (a->second->attach->player != INVALID_GENERIC_ID)
								{
									a->second->attach.reset();
									core->getStreamer()->attachedAreas.erase(a->second);
									core->getGrid()->removeArea(a->second, true);
									return 1;
								}
							}
						}
						return 0;
					}
					case AttachedVehicle:
					{
						if (static_cast<int>(params[4]) != INVALID_GENERIC_ID)
						{
							a->second->attach = boost::intrusive_ptr<Item::Area::Attach>(new Item::Area::Attach);
							a->second->attach->object = boost::make_tuple(INVALID_STREAMER_ID, STREAMER_OBJECT_TYPE_DYNAMIC, INVALID_PLAYER_ID);
							a->second->attach->player = INVALID_GENERIC_ID;
							a->second->attach->position = a->second->position;
							a->second->attach->vehicle = static_cast<int>(params[4]);
							core->getStreamer()->attachedAreas.insert(a->second);
							return 1;
						}
						else
						{
							if (a->second->attach)
							{
								if (a->second->attach->vehicle != INVALID_GENERIC_ID)
								{
									a->second->attach.reset();
									core->getStreamer()->attachedAreas.erase(a->second);
									core->getGrid()->removeArea(a->second, true);
									return 1;
								}
							}
						}
						return 0;
					}
					case ExtraID:
					{
						return Utility::setFirstValueInContainer(a->second->extras, static_cast<int>(params[4])) != 0;
					}
					case InteriorID:
					{
						return Utility::setFirstValueInContainer(a->second->interiors, static_cast<int>(params[4])) != 0;
					}
					case PlayerID:
					{
						return Utility::setFirstValueInContainer(a->second->players, static_cast<int>(params[4])) != 0;
					}
					case Priority:
					{
						a->second->priority = static_cast<int>(params[4]);
						break;
					}
					case WorldID:
					{
						return Utility::setFirstValueInContainer(a->second->worlds, static_cast<int>(params[4])) != 0;
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_ACTOR:
		{
			boost::unordered_map<int, Item::SharedActor>::iterator a = core->getData()->actors.find(static_cast<int>(params[2]));
			if (a != core->getData()->actors.end())
			{
				switch (static_cast<int>(params[3]))
				{
					case AreaID:
					{
						return Utility::setFirstValueInContainer(a->second->areas, static_cast<int>(params[4])) != 0;
					}
					case ExtraID:
					{
						return Utility::setFirstValueInContainer(a->second->extras, static_cast<int>(params[4])) != 0;
					}
					case InteriorID:
					{
						return Utility::setFirstValueInContainer(a->second->interiors, static_cast<int>(params[4])) != 0;
					}
					case Invulnerable:
					{
						a->second->invulnerable = static_cast<int>(params[4]) != 0;
						update = true;
						break;
					}
					case ModelID:
					{
						a->second->modelID = static_cast<int>(params[4]);
						update = true;
						break;
					}
					case PlayerID:
					{
						return Utility::setFirstValueInContainer(a->second->players, static_cast<int>(params[4])) != 0;
					}
					case Priority:
					{
						a->second->priority = static_cast<int>(params[4]);
						return 1;
					}
					case WorldID:
					{
						return Utility::setFirstValueInContainer(a->second->worlds, static_cast<int>(params[4])) != 0;
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
				if (update)
				{
					boost::unordered_map<int, int>::iterator i = core->getData()->internalActors.find(a->first);
					if (i != core->getData()->internalActors.end())
					{
						sampgdk::DestroyActor(i->second);
						i->second = sampgdk::CreateActor(a->second->modelID, a->second->position[0], a->second->position[1], a->second->position[2], a->second->rotation);
						sampgdk::SetActorInvulnerable(i->second, a->second->invulnerable);
						sampgdk::SetActorHealth(i->second, a->second->health);
						sampgdk::SetActorVirtualWorld(i->second, a->second->worldID);
						if (a->second->anim)
						{
							sampgdk::ApplyActorAnimation(i->second, a->second->anim->lib.c_str(), a->second->anim->name.c_str(), a->second->anim->delta, a->second->anim->loop, a->second->anim->lockx, a->second->anim->locky, a->second->anim->freeze, a->second->anim->time);
						}
					}
				}
				return 1;
			}
			else
			{
				error = InvalidID;
			}
			break;
		}
		case STREAMER_TYPE_VEHICLE:
		{
			boost::unordered_map<int, Item::SharedVehicle>::iterator v = core->getData()->vehicles.find(static_cast<int>(params[2]));
			if (v != core->getData()->vehicles.end())
			{
				boost::unordered_map<int, int>::iterator i = core->getData()->internalVehicles.find(v->first);
				switch (static_cast<int>(params[3]))
				{
					case Color:
					{
						v->second->color[0] = static_cast<int>(params[4]);
						if (i != core->getData()->internalVehicles.end())
						{
							sampgdk::ChangeVehicleColor(i->second, v->second->color[0], v->second->color[1]);
						}
					}
					case Color2:
					{
						v->second->color[1] = static_cast<int>(params[4]);
						if (i != core->getData()->internalVehicles.end())
						{
							sampgdk::ChangeVehicleColor(i->second, v->second->color[0], v->second->color[1]);
						}
					}
					case ExtraID:
					{
						return Utility::setFirstValueInContainer(v->second->extras, static_cast<int>(params[4])) != 0;
					}
					case InteriorID:
					{
						v->second->interior = static_cast<int>(params[4]);
						if (i != core->getData()->internalVehicles.end())
						{
							sampgdk::LinkVehicleToInterior(i->second, v->second->interior);
						}
					}
					case ModelID:
					{
						v->second->modelID = static_cast<int>(params[4]);
						update = true;
					}
					case PaintJob:
					{
						v->second->paintjob = static_cast<int>(params[4]);
						if (i != core->getData()->internalVehicles.end())
						{
							sampgdk::ChangeVehiclePaintjob(i->second, v->second->paintjob);
						}
					}
					case Siren:
					{
						v->second->spawn.addsiren = static_cast<int>(params[4]) != 0;
						update = true;
					}
					default:
					{
						error = InvalidData;
						break;
					}
				}
				if (update)
				{
					boost::unordered_map<int, int>::iterator i = core->getData()->internalVehicles.find(v->first);
					if (i != core->getData()->internalVehicles.end())
					{
						sampgdk::DestroyVehicle(i->second);
						i->second = sampgdk::CreateVehicle(v->second->modelID, v->second->position[0], v->second->position[1], v->second->position[2], v->second->angle, v->second->color[0], v->second->color[1], -1, v->second->spawn.addsiren);
						if (i->second == INVALID_VEHICLE_ID)
						{
							return 0;
						}
						if (!v->second->numberplate.empty())
						{
							sampgdk::SetVehicleNumberPlate(i->second, v->second->numberplate.c_str());
						}
						if (v->second->interior)
						{
							sampgdk::LinkVehicleToInterior(i->second, v->second->interior);
						}
						if (v->second->worldID)
						{
							sampgdk::SetVehicleVirtualWorld(i->second, v->second->worldID);
						}
						if (!v->second->carmods.empty())
						{
							for (std::vector<int>::iterator c = v->second->carmods.begin(); c != v->second->carmods.end(); c++)
							{
								sampgdk::AddVehicleComponent(i->second, *c);
							}
						}
						if (v->second->paintjob != 3)
						{
							sampgdk::ChangeVehiclePaintjob(i->second, v->second->paintjob);
						}
						if (v->second->panels != 0 || v->second->doors != 0 || v->second->lights != 0 || v->second->tires != 0)
						{
							sampgdk::UpdateVehicleDamageStatus(i->second, v->second->panels, v->second->doors, v->second->lights, v->second->tires);
						}
						if (v->second->health != 1000.0f)
						{
							sampgdk::SetVehicleHealth(i->second, v->second->health);
						}
						if (v->second->params.engine != VEHICLE_PARAMS_UNSET || v->second->params.lights != VEHICLE_PARAMS_UNSET || v->second->params.alarm != VEHICLE_PARAMS_UNSET || v->second->params.doors != VEHICLE_PARAMS_UNSET || v->second->params.bonnet != VEHICLE_PARAMS_UNSET || v->second->params.boot != VEHICLE_PARAMS_UNSET || v->second->params.objective != VEHICLE_PARAMS_UNSET)
						{
							sampgdk::SetVehicleParamsEx(i->second, v->second->params.engine, v->second->params.lights, v->second->params.alarm, v->second->params.doors, v->second->params.bonnet, v->second->params.boot, v->second->params.objective);
						}
						if (v->second->params.cardoors.driver != VEHICLE_PARAMS_UNSET || v->second->params.cardoors.passenger != VEHICLE_PARAMS_UNSET || v->second->params.cardoors.backleft != VEHICLE_PARAMS_UNSET || v->second->params.cardoors.backright != VEHICLE_PARAMS_UNSET)
						{
							sampgdk::SetVehicleParamsCarDoors(i->second, v->second->params.cardoors.driver, v->second->params.cardoors.passenger, v->second->params.cardoors.backleft, v->second->params.cardoors.backright);
						}
						if (v->second->params.carwindows.driver != VEHICLE_PARAMS_UNSET || v->second->params.carwindows.passenger != VEHICLE_PARAMS_UNSET || v->second->params.carwindows.backleft != VEHICLE_PARAMS_UNSET || v->second->params.carwindows.backright != VEHICLE_PARAMS_UNSET)
						{
							sampgdk::SetVehicleParamsCarWindows(i->second, v->second->params.carwindows.driver, v->second->params.carwindows.passenger, v->second->params.carwindows.backleft, v->second->params.carwindows.backright);
						}
					}
				}
				if (update)
				{
					return 1;
				}
			}
			else
			{
				error = InvalidID;
			}
		}
		default:
		{
			error = InvalidType;
			break;
		}
	}
	switch (error)
	{
		case InvalidData:
		{
			Utility::logError("Streamer_SetIntData: Invalid data specified.");
			break;
		}
		case InvalidID:
		{
			Utility::logError("Streamer_SetIntData: Invalid ID specified.");
			break;
		}
		case InvalidType:
		{
			Utility::logError("Streamer_SetIntData: Invalid type specified.");
			break;
		}
	}
	return 0;
}

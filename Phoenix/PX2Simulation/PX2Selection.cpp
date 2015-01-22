// PX2Selection.cpp

#include "PX2Selection.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2Actor.hpp"
#include "PX2Movable.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Selection::Selection()
{
}
//----------------------------------------------------------------------------
Selection::~Selection()
{
	Clear();
}
//----------------------------------------------------------------------------
void Selection::AddObject(PX2::Object *obj)
{
	assertion(obj != 0, "obj must not be 0.");

	if (IsObjectIn(obj))
		return;

	mObjects.push_back(obj);

	_UpdateSelect();

	Event *emt = 0;
	emt = SimuES_E::CreateEventX(SimuES_E::AddSelect);
	emt->SetData<Object*>(obj);
	EventWorld::GetSingleton().BroadcastingLocalEvent(emt);
}
//----------------------------------------------------------------------------
void Selection::RemoveObject(PX2::Object *obj)
{
	bool removed = false;

	std::vector<ObjectPtr>::iterator it = mObjects.begin();
	for (; it != mObjects.end(); it++)
	{
		if (obj == *it)
		{
			mObjects.erase(it);
			removed = true;
			break;
		}
	}

	if (removed)
	{
		_UpdateSelect();

		Event *emt = 0;
		emt = SimuES_E::CreateEventX(SimuES_E::RemoveSelect);
		emt->SetData<Object*>(obj);
		EventWorld::GetSingleton().BroadcastingLocalEvent(emt);
	}
}
//----------------------------------------------------------------------------
PX2::Object *Selection::GetObjectAt(int i)
{
	if (0 <= i&&i < (int)mObjects.size())
		return mObjects[i];

	return 0;
}
//----------------------------------------------------------------------------
int Selection::GetNumObjects()
{
	return (int)mObjects.size();
}
//----------------------------------------------------------------------------
void Selection::Clear()
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		mObjects[i] = 0;
	}

	mObjects.clear();

	_UpdateSelect();

	Event *ent = 0;
	ent = SimuES_E::CreateEventX(SimuES_E::RemoveAllSelects);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
bool Selection::IsObjectIn(PX2::Object *obj)
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		if (obj == mObjects[i])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Selection::_UpdateSelect()
{
	mCenter = APoint::ORIGIN;
	mBoundRadius = 0.0f;

	APoint pos;
	Bound bound;
	int firstBound = true;

	int numObjects = (int)mObjects.size();
	for (int i = 0; i < numObjects; i++)
	{
		Object *obj = mObjects[i];
		Actor *actor = DynamicCast<Actor>(obj);
		Movable *mov = DynamicCast<Movable>(obj);
		if (actor)
		{
			pos += actor->LocalTransform.GetTranslate();

			Movable *mov = actor->GetNode();
			Movable *helpMov = actor->GetHelpNode();

			bool calHelpMovBound = true;

			if (mov)
			{
				if (0.0f != mov->WorldBound.GetRadius())
				{
					calHelpMovBound = false;

					if (firstBound)
					{
						bound = mov->WorldBound;
						firstBound = false;
					}
					else
					{
						bound.GrowToContain(mov->WorldBound);
					}
				}
				else
				{
					calHelpMovBound = true;
				}
			}
			else
			{
				calHelpMovBound = true;
			}

			if (calHelpMovBound && helpMov)
			{
				if (0.0f != helpMov->WorldBound.GetRadius())
				{
					if (firstBound)
					{
						bound = helpMov->WorldBound;
						firstBound = false;
					}
					else
					{
						bound.GrowToContain(helpMov->WorldBound);
					}
				}
			}
		}
		else if (mov)
		{
			pos += mov->WorldTransform.GetTranslate();

			if (0.0f != mov->WorldBound.GetRadius())
			{
				if (firstBound)
				{
					bound = mov->WorldBound;
					firstBound = false;
				}
				else
				{
					bound.GrowToContain(mov->WorldBound);
				}
			}
		}
	}

	if (numObjects > 0)
	{
		mCenter = pos / (float)numObjects;
		mBoundRadius = bound.GetRadius();
	}
}
//----------------------------------------------------------------------------
#include "Base.h"
#include "ScriptController.h"
#include "lua_PhysicsRigidBody.h"
#include "Animation.h"
#include "AnimationTarget.h"
#include "Base.h"
#include "Game.h"
#include "Image.h"
#include "MeshPart.h"
#include "Node.h"
#include "PhysicsCollisionObject.h"
#include "PhysicsController.h"
#include "PhysicsRigidBody.h"
#include "ScriptController.h"
#include "ScriptTarget.h"
#include "Transform.h"
#include "lua_CurveInterpolationType.h"
#include "lua_PhysicsCollisionObjectCollisionListenerEventType.h"
#include "lua_PhysicsCollisionObjectType.h"
#include "lua_PhysicsCollisionShapeType.h"

namespace gameplay
{

void luaRegister_PhysicsRigidBody()
{
    const luaL_Reg lua_members[] = 
    {
        {"addCollisionListener", lua_PhysicsRigidBody_addCollisionListener},
        {"applyForce", lua_PhysicsRigidBody_applyForce},
        {"applyImpulse", lua_PhysicsRigidBody_applyImpulse},
        {"applyTorque", lua_PhysicsRigidBody_applyTorque},
        {"applyTorqueImpulse", lua_PhysicsRigidBody_applyTorqueImpulse},
        {"collidesWith", lua_PhysicsRigidBody_collidesWith},
        {"getAngularDamping", lua_PhysicsRigidBody_getAngularDamping},
        {"getAngularVelocity", lua_PhysicsRigidBody_getAngularVelocity},
        {"getAnisotropicFriction", lua_PhysicsRigidBody_getAnisotropicFriction},
        {"getCollisionShape", lua_PhysicsRigidBody_getCollisionShape},
        {"getFriction", lua_PhysicsRigidBody_getFriction},
        {"getGravity", lua_PhysicsRigidBody_getGravity},
        {"getHeight", lua_PhysicsRigidBody_getHeight},
        {"getLinearDamping", lua_PhysicsRigidBody_getLinearDamping},
        {"getLinearVelocity", lua_PhysicsRigidBody_getLinearVelocity},
        {"getMass", lua_PhysicsRigidBody_getMass},
        {"getNode", lua_PhysicsRigidBody_getNode},
        {"getRestitution", lua_PhysicsRigidBody_getRestitution},
        {"getShapeType", lua_PhysicsRigidBody_getShapeType},
        {"getType", lua_PhysicsRigidBody_getType},
        {"isDynamic", lua_PhysicsRigidBody_isDynamic},
        {"isEnabled", lua_PhysicsRigidBody_isEnabled},
        {"isKinematic", lua_PhysicsRigidBody_isKinematic},
        {"isStatic", lua_PhysicsRigidBody_isStatic},
        {"removeCollisionListener", lua_PhysicsRigidBody_removeCollisionListener},
        {"setAngularVelocity", lua_PhysicsRigidBody_setAngularVelocity},
        {"setAnisotropicFriction", lua_PhysicsRigidBody_setAnisotropicFriction},
        {"setDamping", lua_PhysicsRigidBody_setDamping},
        {"setEnabled", lua_PhysicsRigidBody_setEnabled},
        {"setFriction", lua_PhysicsRigidBody_setFriction},
        {"setGravity", lua_PhysicsRigidBody_setGravity},
        {"setKinematic", lua_PhysicsRigidBody_setKinematic},
        {"setLinearVelocity", lua_PhysicsRigidBody_setLinearVelocity},
        {"setRestitution", lua_PhysicsRigidBody_setRestitution},
        {NULL, NULL}
    };
    const luaL_Reg* lua_statics = NULL;
    std::vector<std::string> scopePath;

    ScriptUtil::registerClass("PhysicsRigidBody", lua_members, NULL, NULL, lua_statics, scopePath);
}

static PhysicsRigidBody* getInstance(lua_State* state)
{
    void* userdata = luaL_checkudata(state, 1, "PhysicsRigidBody");
    luaL_argcheck(state, userdata != NULL, 1, "'PhysicsRigidBody' expected.");
    return (PhysicsRigidBody*)((ScriptUtil::LuaObject*)userdata)->instance;
}

int lua_PhysicsRigidBody_addCollisionListener(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<PhysicsCollisionObject::CollisionListener> param1 = ScriptUtil::getObjectPointer<PhysicsCollisionObject::CollisionListener>(2, "PhysicsCollisionObjectCollisionListener", false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->addCollisionListener(param1);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TSTRING || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<const char> param1 = ScriptUtil::getString(2, false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->addCollisionListener(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_addCollisionListener - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<PhysicsCollisionObject::CollisionListener> param1 = ScriptUtil::getObjectPointer<PhysicsCollisionObject::CollisionListener>(2, "PhysicsCollisionObjectCollisionListener", false);

                // Get parameter 2 off the stack.
                ScriptUtil::LuaArray<PhysicsCollisionObject> param2 = ScriptUtil::getObjectPointer<PhysicsCollisionObject>(3, "PhysicsCollisionObject", false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->addCollisionListener(param1, param2);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TSTRING || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<const char> param1 = ScriptUtil::getString(2, false);

                // Get parameter 2 off the stack.
                ScriptUtil::LuaArray<PhysicsCollisionObject> param2 = ScriptUtil::getObjectPointer<PhysicsCollisionObject>(3, "PhysicsCollisionObject", false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->addCollisionListener(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_addCollisionListener - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_applyForce(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                PhysicsRigidBody* instance = getInstance(state);
                instance->applyForce(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_applyForce - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                // Get parameter 2 off the stack.
                ScriptUtil::LuaArray<Vector3> param2 = ScriptUtil::getObjectPointer<Vector3>(3, "Vector3", false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->applyForce(*param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_applyForce - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_applyImpulse(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                PhysicsRigidBody* instance = getInstance(state);
                instance->applyImpulse(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_applyImpulse - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                // Get parameter 2 off the stack.
                ScriptUtil::LuaArray<Vector3> param2 = ScriptUtil::getObjectPointer<Vector3>(3, "Vector3", false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->applyImpulse(*param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_applyImpulse - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_applyTorque(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                PhysicsRigidBody* instance = getInstance(state);
                instance->applyTorque(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_applyTorque - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_applyTorqueImpulse(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                PhysicsRigidBody* instance = getInstance(state);
                instance->applyTorqueImpulse(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_applyTorqueImpulse - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_collidesWith(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<PhysicsCollisionObject> param1 = ScriptUtil::getObjectPointer<PhysicsCollisionObject>(2, "PhysicsCollisionObject", false);

                PhysicsRigidBody* instance = getInstance(state);
                bool result = instance->collidesWith(param1);

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_collidesWith - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getAngularDamping(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                float result = instance->getAngularDamping();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getAngularDamping - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getAngularVelocity(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                void* returnPtr = (void*)new Vector3(instance->getAngularVelocity());
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = true;
                    luaL_getmetatable(state, "Vector3");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getAngularVelocity - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getAnisotropicFriction(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                void* returnPtr = (void*)new Vector3(instance->getAnisotropicFriction());
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = true;
                    luaL_getmetatable(state, "Vector3");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getAnisotropicFriction - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getCollisionShape(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                void* returnPtr = (void*)instance->getCollisionShape();
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = false;
                    luaL_getmetatable(state, "PhysicsCollisionShape");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getCollisionShape - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getFriction(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                float result = instance->getFriction();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getFriction - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getGravity(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                void* returnPtr = (void*)new Vector3(instance->getGravity());
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = true;
                    luaL_getmetatable(state, "Vector3");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getGravity - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getHeight(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                float param2 = (float)luaL_checknumber(state, 3);

                PhysicsRigidBody* instance = getInstance(state);
                float result = instance->getHeight(param1, param2);

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getHeight - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 4:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER &&
                (lua_type(state, 4) == LUA_TUSERDATA || lua_type(state, 4) == LUA_TTABLE || lua_type(state, 4) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                float param2 = (float)luaL_checknumber(state, 3);

                // Get parameter 3 off the stack.
                ScriptUtil::LuaArray<Vector3> param3 = ScriptUtil::getObjectPointer<Vector3>(4, "Vector3", false);

                PhysicsRigidBody* instance = getInstance(state);
                float result = instance->getHeight(param1, param2, param3);

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getHeight - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3 or 4).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getLinearDamping(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                float result = instance->getLinearDamping();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getLinearDamping - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getLinearVelocity(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                void* returnPtr = (void*)new Vector3(instance->getLinearVelocity());
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = true;
                    luaL_getmetatable(state, "Vector3");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getLinearVelocity - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getMass(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                float result = instance->getMass();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getMass - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getNode(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                void* returnPtr = (void*)instance->getNode();
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = false;
                    luaL_getmetatable(state, "Node");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getNode - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getRestitution(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                float result = instance->getRestitution();

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getRestitution - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getShapeType(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                PhysicsCollisionShape::Type result = instance->getShapeType();

                // Push the return value onto the stack.
                lua_pushstring(state, lua_stringFromEnum_PhysicsCollisionShapeType(result));

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getShapeType - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_getType(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                PhysicsCollisionObject::Type result = instance->getType();

                // Push the return value onto the stack.
                lua_pushstring(state, lua_stringFromEnum_PhysicsCollisionObjectType(result));

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_getType - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_isDynamic(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                bool result = instance->isDynamic();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_isDynamic - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_isEnabled(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                bool result = instance->isEnabled();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_isEnabled - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_isKinematic(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                bool result = instance->isKinematic();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_isKinematic - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_isStatic(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsRigidBody* instance = getInstance(state);
                bool result = instance->isStatic();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_isStatic - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_removeCollisionListener(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<PhysicsCollisionObject::CollisionListener> param1 = ScriptUtil::getObjectPointer<PhysicsCollisionObject::CollisionListener>(2, "PhysicsCollisionObjectCollisionListener", false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->removeCollisionListener(param1);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TSTRING || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<const char> param1 = ScriptUtil::getString(2, false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->removeCollisionListener(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_removeCollisionListener - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<PhysicsCollisionObject::CollisionListener> param1 = ScriptUtil::getObjectPointer<PhysicsCollisionObject::CollisionListener>(2, "PhysicsCollisionObjectCollisionListener", false);

                // Get parameter 2 off the stack.
                ScriptUtil::LuaArray<PhysicsCollisionObject> param2 = ScriptUtil::getObjectPointer<PhysicsCollisionObject>(3, "PhysicsCollisionObject", false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->removeCollisionListener(param1, param2);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TSTRING || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<const char> param1 = ScriptUtil::getString(2, false);

                // Get parameter 2 off the stack.
                ScriptUtil::LuaArray<PhysicsCollisionObject> param2 = ScriptUtil::getObjectPointer<PhysicsCollisionObject>(3, "PhysicsCollisionObject", false);

                PhysicsRigidBody* instance = getInstance(state);
                instance->removeCollisionListener(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_removeCollisionListener - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_setAngularVelocity(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                PhysicsRigidBody* instance = getInstance(state);
                instance->setAngularVelocity(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_setAngularVelocity - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_setAnisotropicFriction(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                PhysicsRigidBody* instance = getInstance(state);
                instance->setAnisotropicFriction(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_setAnisotropicFriction - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_setDamping(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                lua_type(state, 2) == LUA_TNUMBER &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                // Get parameter 2 off the stack.
                float param2 = (float)luaL_checknumber(state, 3);

                PhysicsRigidBody* instance = getInstance(state);
                instance->setDamping(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_setDamping - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_setEnabled(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                lua_type(state, 2) == LUA_TBOOLEAN)
            {
                // Get parameter 1 off the stack.
                bool param1 = ScriptUtil::luaCheckBool(state, 2);

                PhysicsRigidBody* instance = getInstance(state);
                instance->setEnabled(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_setEnabled - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_setFriction(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                lua_type(state, 2) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                PhysicsRigidBody* instance = getInstance(state);
                instance->setFriction(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_setFriction - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_setGravity(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                PhysicsRigidBody* instance = getInstance(state);
                instance->setGravity(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_setGravity - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_setKinematic(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                lua_type(state, 2) == LUA_TBOOLEAN)
            {
                // Get parameter 1 off the stack.
                bool param1 = ScriptUtil::luaCheckBool(state, 2);

                PhysicsRigidBody* instance = getInstance(state);
                instance->setKinematic(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_setKinematic - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_setLinearVelocity(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                PhysicsRigidBody* instance = getInstance(state);
                instance->setLinearVelocity(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_setLinearVelocity - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsRigidBody_setRestitution(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                lua_type(state, 2) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                float param1 = (float)luaL_checknumber(state, 2);

                PhysicsRigidBody* instance = getInstance(state);
                instance->setRestitution(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsRigidBody_setRestitution - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

}

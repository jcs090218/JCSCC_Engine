#ifndef __D3D11_SCENE2D_H__
#define __D3D11_SCENE2D_H__


#include "D3DX_v11_StdAfx.h"

#include <GameInterface_JCS\JCS_Scene.h>

namespace JCS_D3DX_v11_Engine
{
    class Interface2D;

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Scene
    //
    // Desc : Handle each interface's drawcall in order to render 
    //        all the renderable object in each interface to Scene.
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class Scene2D
        : public JCS_Scene
    {
    private:
        std::vector<Interface2D*> m_interfaces;

    public:
        Scene2D();
        virtual ~Scene2D();

        virtual void initialize() override;
        virtual void update(float32 deltaTime) override;
        virtual void draw() override;

        void AddInterface(Interface2D* pInterface);
        void RemoveInterface(Interface2D* pInterface);

        // setter

        // getter
        std::vector<Interface2D*> GetInterfaces() { return this->m_interfaces; }
        Interface2D* GetInterfacePtrAt(const uint32 index) const { return this->m_interfaces.at(index); }
        Interface2D& GetInterfaceRefAt(const uint32 index) const { return *(this->m_interfaces.at(index)); }
    };

}

#endif // __D3D11_SCENE2D_H__


//
// Created by PinkySmile on 06/10/24.
//

#include "SokuLib.hpp"
#include "Nitori.hpp"
#include "BasicObject.hpp"

extern "C" __declspec(dllexport) SokuLib::v2::Player *buildCharacter(SokuLib::PlayerInfo &p)
{
	printf("Nitori::buildCharacter()\n");
	return new Nitori(p);
}

extern "C" __declspec(dllexport) size_t getCharacterSize()
{
	printf("Nitori::getCharacterSize()\n");
	return sizeof(Nitori);
}

extern "C" __declspec(dllexport) size_t getObjectSize()
{
	printf("Nitori::getObjectSize()\n");
	return sizeof(BasicObject);
}

extern "C" __declspec(dllexport) int APIENTRY DllMain(HMODULE, DWORD fdwReason, LPVOID)
{
	printf("Nitori::DllMain(%lu)\n", fdwReason);
	if (fdwReason == DLL_PROCESS_ATTACH)
		Nitori::hook();
	if (fdwReason == DLL_PROCESS_DETACH)
		Nitori::unhook();
	return TRUE;
}

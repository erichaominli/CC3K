CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = cc3k
OBJECTS = main.o floor.o chamber.o cell.o character.o player.o enemy.o shade.o vampire.o drow.o troll.o goblin.o human.o dwarf.o elf.o orc.o merchant.o dragon.o halfling.o BoostAtk.o BoostDef.o WoundAtk.o WoundDef.o MerchantHoard.o DragonHoard.o Normal.o Small.o Treasure.o Potion.o RestoreHealth.o PoisonHealth.o result.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void printTitle(const std::string &title) {
  std::cout << "\n\033[35m========== " << title << " ==========\033[0m\n";
}

static void printSub(const std::string &title) {
  std::cout << "\033[36m--- " << title << " ---\033[0m\n";
}

int main() {
  std::cout << "\n\033[32m*** CPP04 ex03 giga test main ***\033[0m\n";

  // ************************************************************
  // 1) BASIC SUBJECT TEST
  // ************************************************************
  printTitle("1) Basic subject test");

  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria *tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
  }

  // ************************************************************
  // 2) INVENTORY BEHAVIOR: EQUIP, FULL, INVALID USE / UNEQUIP
  // ************************************************************
  printTitle("2) Inventory & edge cases");

  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character *c = new Character("witch");

    printSub("2.1) Equip up to 4 materias");
    AMateria *m0 = src->createMateria("ice");
    AMateria *m1 = src->createMateria("cure");
    AMateria *m2 = src->createMateria("ice");
    AMateria *m3 = src->createMateria("cure");
    AMateria *m4 =
        src->createMateria("ice"); // will be used to test full inventory

    c->equip(m0);
    c->equip(m1);
    c->equip(m2);
    c->equip(m3);

    printSub("2.2) Try to equip a 5th materia (should do nothing, no crash)");
    c->equip(m4); // inventory full → should not be equipped

    printSub("2.3) Using all slots 0..3");
    Character dummy("dummy");
    for (int i = 0; i < 4; ++i)
      c->use(i, dummy);

    printSub("2.4) Using invalid indices (should do nothing, no crash)");
    c->use(-1, dummy); // invalid
    c->use(4, dummy);  // invalid
    c->use(42, dummy); // invalid

    printSub("2.5) Unequip TEST (no delete inside unequip!)");
    // We'll store the addresses and delete them manually afterward to avoid
    // leaks. If your unequip() wrongly deletes them, this will lead to double
    // free / crash.
    AMateria *floor[5];
    floor[0] = m0;
    floor[1] = m1;
    floor[2] = m2;
    floor[3] = m3;
    floor[4] = m4;

    c->unequip(0);
    c->unequip(1);
    c->unequip(2);
    c->unequip(3);

    printSub("2.6) Try to use after unequip (should do nothing)");
    for (int i = 0; i < 4; ++i)
      c->use(i, dummy);

    delete c;

    printSub("2.7) Manually delete materias dropped on the floor");
    for (int i = 0; i < 5; ++i)
      delete floor[i];

    delete src;
  }

  // ************************************************************
  // 3) UNKNOWN MATERIA TYPE
  // ************************************************************
  printTitle("3) Unknown materia type");

  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());

    AMateria *unk = src->createMateria("fire"); // unknown
    if (!unk)
      std::cout << "createMateria(\"fire\") returned NULL as expected\n";
    else {
      std::cout << "createMateria(\"fire\") returned NON-NULL (unexpected), "
                   "deleting it\n";
      delete unk;
    }

    delete src;
  }

  // ************************************************************
  // 4) DEEP COPY: CHARACTER
  // ************************************************************
  printTitle("4) Deep copy of Character");

  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    printSub("4.1) Original character with 2 materias");
    Character *original = new Character("original");
    original->equip(src->createMateria("ice"));
    original->equip(src->createMateria("cure"));

    Character target("target");
    original->use(0, target);
    original->use(1, target);

    printSub("4.2) Copy construction");
    Character copy(*original); // copy ctor
    copy.use(0, target);
    copy.use(1, target);

    printSub("4.3) Assignment operator");
    Character assigned("assigned");
    assigned = *original;
    assigned.use(0, target);
    assigned.use(1, target);

    printSub("4.4) Delete original, copies must still work (deep copy check)");
    delete original;
    copy.use(0, target);
    copy.use(1, target);
    assigned.use(0, target);
    assigned.use(1, target);

    printSub("4.5) Using invalid slots on copy");
    copy.use(2, target);
    copy.use(3, target);
    copy.use(42, target);

    // copy & assigned will delete their own materias in their destructor
    // if everything is implemented correctly.
    delete src;
  }

  // ************************************************************
  // 5) DEEP COPY: MATERIASOURCE
  // ************************************************************
  printTitle("5) Deep copy of MateriaSource");

  {
    MateriaSource *src1 = new MateriaSource();
    src1->learnMateria(new Ice());
    src1->learnMateria(new Cure());

    printSub("5.1) Copy construct MateriaSource");
    MateriaSource src2(*src1);

    printSub("5.2) Assignment operator MateriaSource");
    MateriaSource src3;
    src3 = *src1;

    printSub("5.3) Create materias from all sources");
    AMateria *a = src1->createMateria("ice");
    AMateria *b = src2.createMateria("ice");
    AMateria *c = src3.createMateria("cure");

    Character dummy("dummy");
    if (a) {
      dummy.equip(a);
      dummy.use(0, dummy);
    }
    if (b) {
      dummy.equip(b);
      dummy.use(1, dummy);
    }
    if (c) {
      dummy.equip(c);
      dummy.use(2, dummy);
    }

    printSub("5.4) Delete original src1, others must still work");
    delete src1;
    AMateria *d = src2.createMateria("cure");
    AMateria *e = src3.createMateria("ice");
    if (d) {
      dummy.equip(d);
      dummy.use(3, dummy);
    }
    if (e) {
      dummy.equip(e);
      dummy.use(0, dummy);
    }

    // Clean up manually all materias we created here
    // (they are equipped in dummy, but dummy's destructor will also delete them
    // if you chose that design; if not, this avoids leaks).
    // To be extra safe in tests, we could unequip and delete, but that depends
    // on your Character design. Adapt if needed.
    // src2 is on the stack, its destructor will run at scope end.
  }

  // ************************************************************
  // 6) STRESS: MIXED EQUIP / UNEQUIP / COPY
  // ************************************************************
  printTitle("6) Stress-ish scenario");

  {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character *a = new Character("A");
    Character *b = new Character("B");

    printSub("6.1) A equips some materias");
    AMateria *m1 = src->createMateria("ice");
    AMateria *m2 = src->createMateria("cure");
    AMateria *m3 = src->createMateria("ice");
    a->equip(m1);
    a->equip(m2);
    a->equip(m3);

    printSub("6.2) A uses materias on B");
    a->use(0, *b);
    a->use(1, *b);
    a->use(2, *b);

    printSub("6.3) Copy A into C, then unequip some from A");
    Character c(*a);
    a->unequip(1); // don't delete inside unequip!

    printSub("6.4) C still has all materias and can use them");
    c.use(0, *b);
    c.use(1, *b);
    c.use(2, *b);

    printSub("6.5) Assignment: D = C");
    Character d("D");
    d = c;
    d.use(0, *b);
    d.use(1, *b);
    d.use(2, *b);

    printSub("6.6) Delete A & B, then use C & D");
    delete a;
    delete b;
    c.use(0, c);
    c.use(1, c);
    c.use(2, c);
    d.use(0, d);
    d.use(1, d);
    d.use(2, d);

    // c and d will clean their own materias.
    delete src;
    // c and d are on the stack, destructors will be called automatically.
  }

  std::cout << "\n\033[32m*** End of giga test main ***\033[0m\n";
  return 0;
}

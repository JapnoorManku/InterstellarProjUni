# Template for CPSC2720 Major Project: Text Based Adventure Game
Last Updated: 2024-10-21 by Nicole Wilson &lt;n.wilson@uleth.ca&gt;

Notes:

* The Makefile and .gitlab-ci.yml files are set up to run on Ubuntu.
* The .gitlab-ci.yml file uses the targets in the Makefile.
* These are the tools/commands/apps used:
  * Compiler: g++
  * Style Check: cpplint
  * Static Check: cppcheck
  * Coverage Check: gcov/lcov
  * Memory Check: valgrind
  * Unit Test: gtest 
  * Documentation: doxygen
* See the version report on the pipeline.

Certain assumptions have been made:
* One repo contains the files for one project.
* All unit testing files are found in <code>test/</code> including <code>main.cpp</code>.
* All header files for the project are found in <code>include/</code> and named <code>*.hpp</code>, every class must have a header file.
* All project source files for the project are named <code>*.cpp</code>.
  * Any needed source files that correspond to header files are found in <code>src/</code>.
  * There is a <code>main.cpp</code> found in <code>src/project/</code>.

# Design Phase
Last updated: 2024-11-08 by Japnoor Manku <japnoor.manku@uleth.ca>
  Group used Discord meetings to coordinate.

  # Suwinya Rajapakse
   - Provided the story background and scenes
   - Assisted in developing the hpp files for environment,item and inventory.
   - Added new environments in the game.
   - Assisted in testfiles aswell

  # Japnoor Manku
   - Created the UML diagram, class and method descriptions in tabular format
   - created hpp files for all the classes and programmed the cpp files for the base game logic.
   - Created the updated UML diagram, did some doxygen comments, did some testfiles
   - Created interactive puzzles that the user than engage in.

  # Nicolas Crespo Cedeno
   - Created the story narrative, game mechanics and functions
   - created hpp files and programmed cpp files for the final phase of the game logic.
   - Integrated the game flow and the logic in the game aswell as added ASCII art
   - Created segways in the game and improved the flow, added taskbar aswell.

  # Moksh Shah
   - created hpp files and assisted in checking and modifying the cpp files for the final game logic.
   - Created test files and helped out with the game flow
   - Assited with the items in the game and in game flow aswell

  The design follows the basic design principles:
  1. Created the classes that are needed for the project.
  2. Determined responsilities for each proposed class, that is, classes follow Single Responsibility Principle.
  3. The design follows the "abstract what is common, encapsulate what varies" principle, that is, Open-Closed Principle.
     Interfaces/abstract classes are created.
  4. The derived classes are substitutable for their base classes, that is, Liskov Substitution Principle is followed.
  5. The derived classes are not being forced to implement methods that they do not need or will not
     use, that is, Interface Segregation Principle is followed.
  6. The design follows the "code to an interface, not an implementation" principle, that is, Dependency Inversion Principle.
     Return types / method parameters are defined.
  7. Design follows the "clean code" practice.
  8. Method description table explains each method in the classes clearly describing it's intention and the purpose of the    parameters.
  9. The UML diagram is placed in the folder docs/design/IntergalacticDesignReport.pdf

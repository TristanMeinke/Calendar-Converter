# Calendar-Converter
A converter to switch between fictional calendars, used as a tool in my writing, as well as an exercise in learning programming and C++. 



This project is the continued refinement of the Calendar Converter project.  It allows the conversion of dates from one
 /  fictional calendar to another, designed at primarily as a tool to improve ease of writing.  Since it's original
 /  conception, it has become something of an academic exercise in flow control and error handling.
 /  *************************************************Version History********************************************************
 /  - Version Alpha was an initial attempt at designing and implementing the conversion formulas, as well as a first design of
 /  the flow control to necessary to take the input from the user and display the output.
 /  - Version Beta implemented superior flow control and the first experiments in error handling.
 /  - Version Gamma implemented string input and string to int conversion, as well as solving input errors still present
 /  in version Beta.  Additionally, this version allowed implemented a dual variable menu, anticipating a reasonable expansion
 /  of the calendars available in later versions.
 /  - Vesrion Delta was intended to break the program down into separate functions designed to work in concert to achieve their
 /  goal.  Learning experience.
 /  -Version Epsilon was intended to streamline the lesser functions and string input.  Epsilon was also be designed to
 /  compensate for rounding errors.
 /  - Version Zeta was created in order to remove dead code (while preserving it in version epsilon), and rework the conversion
 /  formulas for accuracy and cleanliness.  Variable and function names are also altered in the interest of clarity.
 /  - Versrion Eta implemented new functionality.  The main new feature included is the option to calculate one calendar into
 /  all the others.  At present, it only converts to two others, but in theory, it might one day spit out quite a list.  In
 /  order to accomplish this goal, variable 'newdate' removed and supplemented with six more specific replacements, which
 /  ultimately is better anyway, rather than having six functions return the same variable.  With the addition of the
 /  'printResultsOneToAll' function, the 'printResults' function was renamed 'printSingleResults' in the interest of clarity.
 /  Somewhat secondary to the very useful printAll, the function getSnarky was added for this version.  It gets snarky with
 /  the user, particularly over failed input.
 /  - Version Theta added conversions for the Cybernetic Time calendar, and completes the functionality of getSnarky 
 /  (though leaving room for further development).  Additionally, this version compressed
 /  the code of the major print functions by implementing individual print functions for each calculation.
 /  - Version Iota implements a new menu option to the first calendar selector, allowing for more
 /  versatile multiple-conversion options.  Better commenting, and an expansion of the getSnarky responses will be
 /  programmed for this version as well.  Like certain versions, dead code has been removed, and preserved in archived
 /  versions.  As usual, there have been some changes to names of functions and variables to keep up with the times.
 /  Another goal for this version is to fully implement the snarky messages in getSnarky, rather than just the code.
 /  Additionally, getSnarkyImTooDumbForThat might be fun, for reminding the user to use simple input. functions 
 /  datecalcXEtoCT and outputXEtoCT have both been repaired.  Finally, version Iota adds the early prototypes of full date 
 /  conversion, which is to say that it can now convert the decimal remainder of two calendars into 'months' and 'weeks' and 
 /  'days' of sorts. The original was based on user input, but it can now do so automatically. Eventually, it is the goal to 
 /  implement this for all calendars, correct for negative input error, and make the action reversible, so that the program can 
 /  take input in full calendar dates.
 /  ************************************************************************************************************************
 /  Created by Tristan Meinke on 10/30/15.
 /  Copyright © 2015 Tristan Meinke. All rights reserved.

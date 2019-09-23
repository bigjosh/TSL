How to make an anulus from...
https://www.diptrace.com/forum/viewtopic.php?f=2&t=10961

---
Maybe someone else knows of a simpler method, but I haven't figured one out yet. Until then, here is a very involved procedure for getting the pad you need...

Phase I - Option A: Using DipTrace drawing tools
1) In the PCB Layout editor, clear the design area of all objects and make sure Units is set to mm.
2) Using the 2D drawing tools, create the desired shapes (in this case, two circles) in the Top Assy layer centered about the origin (0,0).
3) Go to the Main Menu and click on File, then Export and then DXF...
4) In the Export DXF dialog window, select the Top Assy layer, set Units to mm and enable the option [x]Use Design Origin.
5) Click on the [Export] button and save as a file named sketch to a convenient location (e.g. Desktop).

Phase I - Option B: Using a separate 2D Cad drawing program
1) Create the desired shapes (in this case, two circles) centered about the origin (0,0) using millimeters as your units.
2) Save as a *.DXF file named sketch to a convenient location (e.g. Desktop).

Phase II
1) In the PCB Layout editor, clear the design area of all objects and make sure Units is set to mm.
2) Go to the Main Menu and click on File, then Import and then DXF...
3) Select the newly-created file named sketch.dxf.
4) In the Import DXF dialog window, set DXF Units: Millimeters, Import Mode: Add, Convert Blocks: None, Convert to: Top, enable options [x]Fill closed areas and [x]Embedded Polygons.
5) Click on the [Import] button.
6) Go to the Main Menu and click on File, then Export and then DXF...
7) In the Export DXF dialog window, select the Top layer, set Units to mm and enable the option [x]Use Design Origin.
8) Click on the [Export] button and save as a file named pad to a convenient location (e.g. Desktop).

Phase III
1) In the Pattern Editor, create a new pattern name and clear the design area of all objects. Make sure Units is set to mm.
2) Go to the Main Menu and click on Pattern and then Import from DXF...
3) Choose the newly-created file named pad.dxf.
4) In the Import DXF dialog window, set DXF Units: Millimeters, Import Mode: Add, Convert to: Top Pads, enable options [x]Fill Closed Areas and [x]Embedded Polygons.
5) Click on the [Import] button.

Note: Due to how this special pad was created, you will not be able to resize it. Also, copying this special pad will result in the copies having the same pad number. You will have to manually renumber those additional pads.
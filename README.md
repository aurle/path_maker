# How to create a path for frc

The purpose of this project was to originally to render a series of poses or waypoints for a robot to pass through by simply drawing them on a screen. From there, it has been changed so that FRC teams who have implemented drive straight and rotate commands on their robot can draw paths and generate the drive straight and rotate commands they can feed into their robot to have it follow the path. The idea is to provide an ability to generate more complex paths in a visual way using the existing drive straight and rotate commands they may already have.

1) Install LibreCad  https://librecad.org/
2) Get an image of  the playing field or a path that you want to trace. Do this with a screenshot. To make things easier, try to create the image so (0,0) is the bottom left hand corner of the image.

![](images/image3.png)

3) Set the units of the drawing (options->current drawing preferences->main drawing unit) to be the units used for robot navigation. For example, if the robot code is using inches in drive straight, set units to inches. If using mm in drive straight, set units to mm.
4) Insert the image into the drawing. (file->import->image) and then click on the drawing origin. It may be helpful to enable the snap on grid option at the bottom left hand corner of the screen first so you will snap onto (0,0)
5) If the bottom left hand corner of the image does not represent (0,0) of the axes, move the image with a tools->modify->move/copy command. Select the (0,0) point on the image as the reference point and then (0,0) in the drawing as the new location. If the bottom left hand corner of the image is (0,0) this step can be skipped, because the image is already there. If the image does have to be moved, there is a bug in librecad for Mac, so if this is being done on a Mac the moved image may not be visible immediately after the move. Save the file, close it, and re-open it and will appear correctly. If (0,0) is the bottom left corner of the image, you can skip this step entirely.
6) Now the image needs to be scaled to make it match the units of the drawing. Move the cursor to a known position on the image. For example, on the above image, it is known that D2 is at 5 feet x, 5 feet y. When the cursor is moved over that point, there will be coordinates displayed in the bottom left hand corner of the screen. They are displayed in the units the drawing was set to. So if the drawing is set to inches, 5 feet would be 60 and 60. If the coordinates displayed are larger than 60, the image needs to be scaled down so the image matches the units of the drawing. Divide the number the point really is by the number reported when the cursor is over the point. So, if the number displayed when the cursor is over the point is 332, 60/332 = 0.18072.     
7) Select the image and then select tools->modify scale.
8) When asked to select a reference point, just pick (0,0) because the objective here is just to resize, not move. Then enter the number calculated in step 4 as the scaling factor.

![](images/image6.png)

8) Select ok
9) There is a bug in the Mac version of LibreCad so the immediate results of the scaling after ok has been selected may not be displayed correctly. Save the drawing, close it, and reopen it and now the properly scaled image should appear.
10) Now if the cursor is moved over the known point, it should show the actual coordinates of that location in the units the drawing is set to. So if the cursor is moved over point d2, it should read (60,60), or close to it.

![](images/image5.png)

11) Create a new layer called Path by clicking the green plus sign in the layer list dialog on the top right hand side of the screen. This is optional, but keeps things neat.  The layer color and line width can be changed here too if desired, but that is also optional.

![](images/image2.png)

12) Make sure the new layer is selected, because the selected layer is where the drawing/lines will be placed. By having two layers the view of the path and the view of the image can be toggled on and off.
13) Select the 2 points line drawing tool from the left side menu.

![](images/image4.png)

14) Now, the path it is desired the robot travel can just be drawn on the display. In this example, the example path is traced exactly. Just draw straight lines as needed to duplicate the path. The start point will be (0,0) with no heading and all of the following lines will be reference from there. Any path desired can be created.

![](images/image1.png)

15) Save the file. It will be saved as a dxf file.
16) Get conversion code from this project https://github.com/aurle/path_maker
17) The file you want here is dxf2frc.cpp
18) Run make to build it, or build it with g++ -o dxf2frc dxf2frc.cpp
19) Make it executable with chmod a+x dxf2frc
20) Generate commands for the path with ./dxf2frc filename.dxf  where filename.dxf is the name of the file you saved in librecad.
21) This will generate the drive straight and rotate commands needed to follow the path that was drawn. Output will look something like this.
./dxf2frc layouts.dxf 

drive straight 25.961510:  
rotate 4.332321 

drive straight 20.396078:  
rotate 4.969734 

drive straight 18.110771:  
rotate 6.340195 

drive straight 16.000000:  
rotate 9.462318 

drive straight 12.165525:  
rotate 8.972633 

drive straight 9.486833:  
rotate 16.557068 

drive straight 12.206555:  
rotate 10.007980 

drive straight 11.313708:  
rotate 22.380142 

drive straight 13.000000:  
rotate 16.909271 

drive straight 10.049875:  
rotate 19.746826 

drive straight 8.246211:  
rotate 36.158188 

drive straight 7.810250:  
rotate 25.769318 


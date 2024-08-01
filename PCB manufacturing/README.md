# Manufacturing of PCBS with Solder Mask
![IMG_7378](https://github.com/user-attachments/assets/c0d4c2f1-4def-424f-97cf-cc3a0be6e29d)
Printed Circuit Boards (PCBs) are essential components in electronic devices, providing the necessary platform for mounting and connecting electronic components. One of the DIY-friendly methods for PCB manufacturing is the toner transfer method. This repo outlines the process of manufacturing PCBs using the toner transfer technique, highlighting each step involved.
1. Design Preparation
1.1 Schematic Capture
The process begins with designing the circuit schematic using Electronic Design Automation (EDA) software we use EASYEDA. The schematic is a blueprint of the electrical connections and components.
![main_Schematic](https://github.com/user-attachments/assets/bdc470ab-c9f0-44b3-b7dc-fc4dae3cfe45)

1.2 Layout Design
The schematic is converted into a PCB layout using the same EDA software. This layout includes the placement of components and routing of copper traces. Once finalized, the layout is printed onto glossy paper or special toner transfer paper using a laser printer.
2. Substrate Preparation
![secondary_Schematic](https://github.com/user-attachments/assets/73a4351d-982e-409a-8036-3926abc09d02)

2.1 Cleaning
A copper-clad board, typically made of fiberglass with a layer of copper, is used as the substrate. The copper surface is thoroughly cleaned using fine steel wool or abrasive pads to remove any oxidation and contaminants, ensuring good adhesion of the toner.
![IMG_7354 (1)](https://github.com/user-attachments/assets/c4b60df1-af61-4895-a6d2-db81d67bea3e)

3. Toner Transfer
3.1 Aligning and Fixing
The printed design is placed toner-side down onto the cleaned copper-clad board. It is essential to align the design correctly to ensure accurate transfer.
3.2 Toner Transfer
Using Toner or Acetone to wet the paper with copper layer and with some pressure the ink stick to the copper
 
3.3 Removing the Paper
the paper is soaked in water to soften it. The paper is then carefully removed, leaving the toner on the copper, which now acts as a resist for the etching process.
 
4. Etching
The board is submerged in an etching solution, typically ferric chloride or ammonium persulfate. The solution removes the exposed copper, leaving only the copper traces protected by the toner. This process is done in a well-ventilated area, using appropriate safety measures.
 
5. Toner Removal
After etching, the toner is removed using acetone or isopropyl alcohol, revealing the copper traces that form the circuit.
  
6. Drilling
A drill press or a handheld drill with fine drill bits is used to create holes for through-hole components and vias. Precision is crucial to ensure proper component placement.

7. Solder Mask Application
Applying a solder mask to a printed circuit board (PCB) is an essential step in ensuring the board’s durability and reliability. A solder mask protects the copper traces from oxidation, prevents solder bridges during soldering, and improves the overall appearance of the PCB. One effective method for applying a solder mask is using a silk screen frame. This report provides a step-by-step guide on how to create and apply a solder mask using this technique.
Materials and Tools Needed
•	Cleaned PCB with exposed copper traces
•	Silk screen frame with fine mesh
•	Solder mask ink (e.g., UV curable or thermal curing solder mask)
•	Squeegee
•	Transparent film with the solder mask pattern (positive or negative image)
•	UV light source (for UV curable masks)
•	Developer solution (if using a photoimageable solder mask)
•	Curing oven (if using thermal curing solder mask)
•	Protective gloves and goggles
•	Isopropyl alcohol or acetone
•	Fine abrasive pad or steel wool (for initial cleaning)
Step-by-Step Process
1. Preparing the PCB
1.	Cleaning: Ensure the PCB is clean and free of any contaminants. Use a fine abrasive pad or steel wool to scrub the copper surface lightly. Clean the board with isopropyl alcohol or acetone and let it dry completely.
2. Preparing the Silk Screen
1.	Design Preparation: Print the solder mask pattern onto a transparent film. This pattern should expose areas where solder will be applied and protect the rest of the board.
  
2.	Setting Up the Screen: Attach the transparent film to the silk screen frame. Ensure that the film is aligned correctly with the PCB layout. The screen should have a fine mesh suitable for detailed work.
  
3. Applying the Solder Mask
1.	Applying the Solder Mask Ink: Pour a small amount of solder mask ink onto the silk screen.  
2.	Spreading the Ink: Using a squeegee, spread the solder mask ink evenly across the screen. The ink will pass through the mesh in areas not blocked by the pattern, transferring the solder mask design onto the PCB.
  

3.	Positioning the PCB: Place the cleaned PCB under the silk screen frame. Ensure it is properly aligned with the pattern on the transparent film.
 

4.	Checking Coverage: Carefully lift the silk screen frame and inspect the PCB to ensure the solder mask has been applied correctly. All areas that need to be protected should be covered with the solder mask ink.
4. Curing the Solder Mask
1.	UV Curable Solder Mask:
o	Exposure: Place the PCB under a UV light source, exposing it for the recommended amount of time specified by the solder mask manufacturer.  
o	Developing: If using a photoimageable solder mask, immerse the PCB in the developer solution to remove unexposed areas, revealing the solder mask pattern.
2.	Thermal Curing Solder Mask:
o	Curing: Place the PCB in a curing oven and bake it at the temperature and duration specified by the solder mask manufacturer.
5. Final Inspection and Touch-Up
1.	Inspection: Inspect the cured solder mask for any defects or areas where coverage is inadequate. Use a magnifying glass or microscope for detailed inspection.  
2.	Touch-Up: If necessary, use a small brush to apply additional solder mask ink to any missed spots and cure as needed.
6. Cleaning and Finishing
1.	Cleaning: Clean the PCB with isopropyl alcohol or acetone to remove any residual developer or uncured ink.
2.	Finishing: Lightly sand the solder mask surface to smooth out any rough edges or uneven areas.
 

8. Assembly
8.1 Component Placement
Components are manually placed on the board according to the design. 
8.2 Soldering
Components are soldered using a soldering iron. For SMD components, a reflow oven or hot air gun may be used to melt solder paste applied during placement.
9. Testing and Inspection
9.1 Visual Inspection
A through visual inspection is conducted to check for any visible defects such as solder bridges, misaligned components, or incomplete etching.
9.2 Electrical Testing
Basic electrical tests are performed to ensure continuity and correct connections. Multimeters or simple test circuits can be used to verify functionality.
 


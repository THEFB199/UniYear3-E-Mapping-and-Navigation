  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (PI_UDP_Recieve_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_P.CounterLimited_uplimit
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_P.Constant_Value
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_P.Lx_Y0
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PI_UDP_Recieve_P.Ly_Y0
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PI_UDP_Recieve_P.Lz_Y0
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PI_UDP_Recieve_P.Ax_Y0
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PI_UDP_Recieve_P.Ay_Y0
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PI_UDP_Recieve_P.Az_Y0
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PI_UDP_Recieve_P.Gain7_Gain
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable9_tableData
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable9_bp01Data
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 12;
	
	  ;% PI_UDP_Recieve_P.Gain8_Gain
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 17;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable1_tableData
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 18;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable1_bp01Data
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 23;
	
	  ;% PI_UDP_Recieve_P.Constant4_Value
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 28;
	
	  ;% PI_UDP_Recieve_P.Gain6_Gain
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 29;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable7_tableData
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 30;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable7_bp01Data
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 35;
	
	  ;% PI_UDP_Recieve_P.Constant5_Value
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 40;
	
	  ;% PI_UDP_Recieve_P.Gain2_Gain
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 41;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable1_tableData_g
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 42;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable1_bp01Data_b
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 47;
	
	  ;% PI_UDP_Recieve_P.Constant6_Value
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 52;
	
	  ;% PI_UDP_Recieve_P.Gain3_Gain
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 53;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable2_tableData
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 54;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable2_bp01Data
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 57;
	
	  ;% PI_UDP_Recieve_P.Constant7_Value
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 60;
	
	  ;% PI_UDP_Recieve_P.Gain1_Gain
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 61;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable3_tableData
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 62;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable3_bp01Data
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 65;
	
	  ;% PI_UDP_Recieve_P.Constant2_Value
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 68;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_P.Constant_Value_m
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PI_UDP_Recieve_P.Output_InitialCondition
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PI_UDP_Recieve_P.FixPtConstant_Value
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (PI_UDP_Recieve_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_B.In1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_B.Left_right
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PI_UDP_Recieve_B.Up_Down
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PI_UDP_Recieve_B.Up_Down_h
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PI_UDP_Recieve_B.uDLookupTable1
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PI_UDP_Recieve_B.Left_right_c
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PI_UDP_Recieve_B.Up_Down_n
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PI_UDP_Recieve_B.Constant2
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PI_UDP_Recieve_B.DataTypeConversion1
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PI_UDP_Recieve_B.DataTypeConversion2
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PI_UDP_Recieve_B.DataTypeConversion3
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PI_UDP_Recieve_B.DataTypeConversion4
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 10;
	
	  ;% PI_UDP_Recieve_B.DataTypeConversion5
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 11;
	
	  ;% PI_UDP_Recieve_B.DataTypeConversion6
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_B.SPIMasterTransfer
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_B.Output
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (PI_UDP_Recieve_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_DW.obj_c
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_DW.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PI_UDP_Recieve_DW.GetRosMessage_SubsysRanBC
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3389596803;
  targMap.checksum1 = 4147866139;
  targMap.checksum2 = 3992559819;
  targMap.checksum3 = 2027735132;


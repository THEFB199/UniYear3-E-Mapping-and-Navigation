  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_P.UDPReceive_Port
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_P.Gain7_Gain
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable9_tableData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable9_bp01Data
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 6;
	
	  ;% PI_UDP_Recieve_P.Gain8_Gain
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 11;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable1_tableData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 12;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable1_bp01Data
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 17;
	
	  ;% PI_UDP_Recieve_P.Gain6_Gain
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 22;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable7_tableData
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 23;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable7_bp01Data
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 28;
	
	  ;% PI_UDP_Recieve_P.Gain2_Gain
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 33;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable1_tableData_g
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 34;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable1_bp01Data_b
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 39;
	
	  ;% PI_UDP_Recieve_P.Gain3_Gain
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 44;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable2_tableData
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 45;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable2_bp01Data
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 48;
	
	  ;% PI_UDP_Recieve_P.Gain1_Gain
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 51;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable3_tableData
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 52;
	
	  ;% PI_UDP_Recieve_P.uDLookupTable3_bp01Data
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 55;
	
	  ;% PI_UDP_Recieve_P.Constant2_Value
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_P.Constant_Value_m
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PI_UDP_Recieve_P.Output_InitialCondition
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PI_UDP_Recieve_P.FixPtConstant_Value
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    nTotSects     = 3;
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
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_B.Left_right
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PI_UDP_Recieve_B.Up_Down
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PI_UDP_Recieve_B.Axes
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PI_UDP_Recieve_B.Up_Down_h
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 8;
	
	  ;% PI_UDP_Recieve_B.uDLookupTable1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 9;
	
	  ;% PI_UDP_Recieve_B.Left_right_c
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% PI_UDP_Recieve_B.Up_Down_n
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 11;
	
	  ;% PI_UDP_Recieve_B.Constant2
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_B.UDPReceive_o2
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PI_UDP_Recieve_B.SPIMasterTransfer
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_B.Output
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
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
    nTotSects     = 6;
    sectIdxOffset = 3;
    
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
      
	  ;% PI_UDP_Recieve_DW.UDPReceive_NetworkLib
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_DW.RateTransition1_Buffer
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PI_UDP_Recieve_DW.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
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


  targMap.checksum0 = 4137458206;
  targMap.checksum1 = 1570638343;
  targMap.checksum2 = 1925585545;
  targMap.checksum3 = 4019662560;


  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
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
    ;% Auto data (ROSPiNav2_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_P.CounterLimited_uplimit
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_P.Constant_Value
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_P.Out1_Y0_d
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_P.Constant_Value_j
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% ROSPiNav2_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ROSPiNav2_P.Constant_Value_f
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ROSPiNav2_P.Lx_Y0
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ROSPiNav2_P.Ly_Y0
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ROSPiNav2_P.Lz_Y0
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ROSPiNav2_P.Ax_Y0
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ROSPiNav2_P.Ay_Y0
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ROSPiNav2_P.Az_Y0
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ROSPiNav2_P.LeftRightL_Y0
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ROSPiNav2_P.UpDownL_Y0
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ROSPiNav2_P.LeftTrigger_Y0
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ROSPiNav2_P.LeftRightR_Y0
	  section.data(12).logicalSrcIdx = 16;
	  section.data(12).dtTransOffset = 11;
	
	  ;% ROSPiNav2_P.UpDownR_Y0
	  section.data(13).logicalSrcIdx = 17;
	  section.data(13).dtTransOffset = 12;
	
	  ;% ROSPiNav2_P.RightTrigger_Y0
	  section.data(14).logicalSrcIdx = 18;
	  section.data(14).dtTransOffset = 13;
	
	  ;% ROSPiNav2_P.LeftRightDpad_Y0
	  section.data(15).logicalSrcIdx = 19;
	  section.data(15).dtTransOffset = 14;
	
	  ;% ROSPiNav2_P.UpDownDpad_Y0
	  section.data(16).logicalSrcIdx = 20;
	  section.data(16).dtTransOffset = 15;
	
	  ;% ROSPiNav2_P.Buttons_Y0
	  section.data(17).logicalSrcIdx = 21;
	  section.data(17).dtTransOffset = 16;
	
	  ;% ROSPiNav2_P.DeadZone_Start
	  section.data(18).logicalSrcIdx = 22;
	  section.data(18).dtTransOffset = 17;
	
	  ;% ROSPiNav2_P.DeadZone_End
	  section.data(19).logicalSrcIdx = 23;
	  section.data(19).dtTransOffset = 18;
	
	  ;% ROSPiNav2_P.uDLookupTable1_tableData
	  section.data(20).logicalSrcIdx = 24;
	  section.data(20).dtTransOffset = 19;
	
	  ;% ROSPiNav2_P.uDLookupTable1_bp01Data
	  section.data(21).logicalSrcIdx = 25;
	  section.data(21).dtTransOffset = 22;
	
	  ;% ROSPiNav2_P.Gain1_Gain
	  section.data(22).logicalSrcIdx = 26;
	  section.data(22).dtTransOffset = 25;
	
	  ;% ROSPiNav2_P.uDLookupTable9_tableData
	  section.data(23).logicalSrcIdx = 27;
	  section.data(23).dtTransOffset = 26;
	
	  ;% ROSPiNav2_P.uDLookupTable9_bp01Data
	  section.data(24).logicalSrcIdx = 28;
	  section.data(24).dtTransOffset = 31;
	
	  ;% ROSPiNav2_P.uDLookupTable1_tableData_b
	  section.data(25).logicalSrcIdx = 29;
	  section.data(25).dtTransOffset = 36;
	
	  ;% ROSPiNav2_P.uDLookupTable1_bp01Data_g
	  section.data(26).logicalSrcIdx = 30;
	  section.data(26).dtTransOffset = 41;
	
	  ;% ROSPiNav2_P.Constant5_Value
	  section.data(27).logicalSrcIdx = 31;
	  section.data(27).dtTransOffset = 46;
	
	  ;% ROSPiNav2_P.Constant4_Value
	  section.data(28).logicalSrcIdx = 32;
	  section.data(28).dtTransOffset = 47;
	
	  ;% ROSPiNav2_P.Constant3_Value
	  section.data(29).logicalSrcIdx = 33;
	  section.data(29).dtTransOffset = 48;
	
	  ;% ROSPiNav2_P.Constant1_Value
	  section.data(30).logicalSrcIdx = 34;
	  section.data(30).dtTransOffset = 49;
	
	  ;% ROSPiNav2_P.EndofData_Value
	  section.data(31).logicalSrcIdx = 35;
	  section.data(31).dtTransOffset = 50;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ROSPiNav2_P.Constant_Value_a
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ROSPiNav2_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ROSPiNav2_P.Output_InitialCondition
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ROSPiNav2_P.FixPtConstant_Value
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (ROSPiNav2_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_B.In1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_B.In1_l
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% ROSPiNav2_B.uDLookupTable9
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ROSPiNav2_B.uDLookupTable1
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ROSPiNav2_B.uDLookupTable1_j
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ROSPiNav2_B.OutportBufferForUpDownL
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 6;
	
	  ;% ROSPiNav2_B.DataTypeConversion1
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 7;
	
	  ;% ROSPiNav2_B.DataTypeConversion2
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 8;
	
	  ;% ROSPiNav2_B.DataTypeConversion3
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 9;
	
	  ;% ROSPiNav2_B.DataTypeConversion4
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 10;
	
	  ;% ROSPiNav2_B.DataTypeConversion5
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 11;
	
	  ;% ROSPiNav2_B.DataTypeConversion6
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_B.SPIMasterTransfer
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_B.Output
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ROSPiNav2_B.SourceBlock_o1
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ROSPiNav2_B.SourceBlock_o1_g
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
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
    sectIdxOffset = 6;
    
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
    ;% Auto data (ROSPiNav2_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ROSPiNav2_DW.obj_l
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ROSPiNav2_DW.obj_e
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ROSPiNav2_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ROSPiNav2_DW.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ROSPiNav2_DW.EnabledSubsystem_SubsysRanBC_j
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ROSPiNav2_DW.GetRosMessage1_SubsysRanBC
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ROSPiNav2_DW.GetRosMessage_SubsysRanBC
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
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


  targMap.checksum0 = 1707139660;
  targMap.checksum1 = 647649131;
  targMap.checksum2 = 1106900136;
  targMap.checksum3 = 1223125444;


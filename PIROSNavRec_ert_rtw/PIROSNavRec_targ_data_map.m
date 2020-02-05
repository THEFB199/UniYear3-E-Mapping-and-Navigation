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
    ;% Auto data (PIROSNavRec_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_P.CounterLimited_uplimit
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_P.Constant_Value
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% PIROSNavRec_P.Gain8_Gain
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PIROSNavRec_P.Constant_Value_b
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PIROSNavRec_P.Lx_Y0
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PIROSNavRec_P.Ly_Y0
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PIROSNavRec_P.Lz_Y0
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PIROSNavRec_P.Ax_Y0
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% PIROSNavRec_P.Ay_Y0
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% PIROSNavRec_P.Az_Y0
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% PIROSNavRec_P.Gain7_Gain
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
	  ;% PIROSNavRec_P.uDLookupTable9_tableData
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 9;
	
	  ;% PIROSNavRec_P.uDLookupTable9_bp01Data
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 14;
	
	  ;% PIROSNavRec_P.uDLookupTable1_tableData
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 19;
	
	  ;% PIROSNavRec_P.uDLookupTable1_bp01Data
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 24;
	
	  ;% PIROSNavRec_P.Constant5_Value
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 29;
	
	  ;% PIROSNavRec_P.Constant4_Value
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 30;
	
	  ;% PIROSNavRec_P.Constant3_Value
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 31;
	
	  ;% PIROSNavRec_P.Constant1_Value
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 32;
	
	  ;% PIROSNavRec_P.Constant2_Value
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 33;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% PIROSNavRec_P.Constant_Value_i
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PIROSNavRec_P.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PIROSNavRec_P.Output_InitialCondition
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PIROSNavRec_P.FixPtConstant_Value
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (PIROSNavRec_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_B.In1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% PIROSNavRec_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PIROSNavRec_B.DataTypeConversion2
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% PIROSNavRec_B.DataTypeConversion3
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% PIROSNavRec_B.DataTypeConversion4
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% PIROSNavRec_B.DataTypeConversion5
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
	  ;% PIROSNavRec_B.DataTypeConversion6
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_B.SPIMasterTransfer
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_B.Output
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_B.SourceBlock_o1
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
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
    sectIdxOffset = 5;
    
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
    ;% Auto data (PIROSNavRec_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_DW.obj_n
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% PIROSNavRec_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% PIROSNavRec_DW.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% PIROSNavRec_DW.GetRosMessage_SubsysRanBC
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


  targMap.checksum0 = 1443270732;
  targMap.checksum1 = 1408371606;
  targMap.checksum2 = 2369941699;
  targMap.checksum3 = 295741023;


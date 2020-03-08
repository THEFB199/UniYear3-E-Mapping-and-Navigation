function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "untitled1"};
	this.sidHashMap["untitled1"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "untitled1:1"};
	this.sidHashMap["untitled1:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "untitled1:4"};
	this.sidHashMap["untitled1:4"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "untitled1:1:3"};
	this.sidHashMap["untitled1:1:3"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "untitled1:1:5"};
	this.sidHashMap["untitled1:1:5"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<Root>/Counter Limited"] = {sid: "untitled1:1"};
	this.sidHashMap["untitled1:1"] = {rtwname: "<Root>/Counter Limited"};
	this.rtwnameHashMap["<Root>/Display"] = {sid: "untitled1:2"};
	this.sidHashMap["untitled1:2"] = {rtwname: "<Root>/Display"};
	this.rtwnameHashMap["<Root>/SDL Video Display"] = {sid: "untitled1:4"};
	this.sidHashMap["untitled1:4"] = {rtwname: "<Root>/SDL Video Display"};
	this.rtwnameHashMap["<Root>/V4L2 Video Capture"] = {sid: "untitled1:3"};
	this.sidHashMap["untitled1:3"] = {rtwname: "<Root>/V4L2 Video Capture"};
	this.rtwnameHashMap["<S1>/Data Type Propagation"] = {sid: "untitled1:1:1"};
	this.sidHashMap["untitled1:1:1"] = {rtwname: "<S1>/Data Type Propagation"};
	this.rtwnameHashMap["<S1>/Force to be scalar"] = {sid: "untitled1:1:2"};
	this.sidHashMap["untitled1:1:2"] = {rtwname: "<S1>/Force to be scalar"};
	this.rtwnameHashMap["<S1>/Increment Real World"] = {sid: "untitled1:1:3"};
	this.sidHashMap["untitled1:1:3"] = {rtwname: "<S1>/Increment Real World"};
	this.rtwnameHashMap["<S1>/Output"] = {sid: "untitled1:1:4"};
	this.sidHashMap["untitled1:1:4"] = {rtwname: "<S1>/Output"};
	this.rtwnameHashMap["<S1>/Wrap To Zero"] = {sid: "untitled1:1:5"};
	this.sidHashMap["untitled1:1:5"] = {rtwname: "<S1>/Wrap To Zero"};
	this.rtwnameHashMap["<S1>/y"] = {sid: "untitled1:1:6"};
	this.sidHashMap["untitled1:1:6"] = {rtwname: "<S1>/y"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "untitled1:4:14"};
	this.sidHashMap["untitled1:4:14"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/In2"] = {sid: "untitled1:4:15"};
	this.sidHashMap["untitled1:4:15"] = {rtwname: "<S2>/In2"};
	this.rtwnameHashMap["<S2>/In3"] = {sid: "untitled1:4:16"};
	this.sidHashMap["untitled1:4:16"] = {rtwname: "<S2>/In3"};
	this.rtwnameHashMap["<S2>/Level-2 MATLAB S-Function"] = {sid: "untitled1:4:10"};
	this.sidHashMap["untitled1:4:10"] = {rtwname: "<S2>/Level-2 MATLAB S-Function"};
	this.rtwnameHashMap["<S2>/MATLAB System"] = {sid: "untitled1:4:11"};
	this.sidHashMap["untitled1:4:11"] = {rtwname: "<S2>/MATLAB System"};
	this.rtwnameHashMap["<S3>/u"] = {sid: "untitled1:1:3:1"};
	this.sidHashMap["untitled1:1:3:1"] = {rtwname: "<S3>/u"};
	this.rtwnameHashMap["<S3>/FixPt Constant"] = {sid: "untitled1:1:3:2"};
	this.sidHashMap["untitled1:1:3:2"] = {rtwname: "<S3>/FixPt Constant"};
	this.rtwnameHashMap["<S3>/FixPt Data Type Duplicate"] = {sid: "untitled1:1:3:3"};
	this.sidHashMap["untitled1:1:3:3"] = {rtwname: "<S3>/FixPt Data Type Duplicate"};
	this.rtwnameHashMap["<S3>/FixPt Sum1"] = {sid: "untitled1:1:3:4"};
	this.sidHashMap["untitled1:1:3:4"] = {rtwname: "<S3>/FixPt Sum1"};
	this.rtwnameHashMap["<S3>/y"] = {sid: "untitled1:1:3:5"};
	this.sidHashMap["untitled1:1:3:5"] = {rtwname: "<S3>/y"};
	this.rtwnameHashMap["<S4>/U"] = {sid: "untitled1:1:5:1"};
	this.sidHashMap["untitled1:1:5:1"] = {rtwname: "<S4>/U"};
	this.rtwnameHashMap["<S4>/Constant"] = {sid: "untitled1:1:5:4"};
	this.sidHashMap["untitled1:1:5:4"] = {rtwname: "<S4>/Constant"};
	this.rtwnameHashMap["<S4>/FixPt Data Type Duplicate1"] = {sid: "untitled1:1:5:2"};
	this.sidHashMap["untitled1:1:5:2"] = {rtwname: "<S4>/FixPt Data Type Duplicate1"};
	this.rtwnameHashMap["<S4>/FixPt Switch"] = {sid: "untitled1:1:5:3"};
	this.sidHashMap["untitled1:1:5:3"] = {rtwname: "<S4>/FixPt Switch"};
	this.rtwnameHashMap["<S4>/Y"] = {sid: "untitled1:1:5:5"};
	this.sidHashMap["untitled1:1:5:5"] = {rtwname: "<S4>/Y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();

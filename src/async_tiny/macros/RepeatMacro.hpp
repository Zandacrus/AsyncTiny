#pragma once


#define REPEAT_0_(MACRO, ...) 

#define REPEAT_1_(MACRO, ...) \
MACRO(1, ##__VA_ARGS__)

#define REPEAT_2_(MACRO, ...) \
MACRO(2, ##__VA_ARGS__) \
REPEAT_1_(MACRO, ##__VA_ARGS__)

#define REPEAT_3_(MACRO, ...) \
MACRO(3, ##__VA_ARGS__) \
REPEAT_2_(MACRO, ##__VA_ARGS__)

#define REPEAT_4_(MACRO, ...) \
MACRO(4, ##__VA_ARGS__) \
REPEAT_3_(MACRO, ##__VA_ARGS__)

#define REPEAT_5_(MACRO, ...) \
MACRO(5, ##__VA_ARGS__) \
REPEAT_4_(MACRO, ##__VA_ARGS__)

#define REPEAT_6_(MACRO, ...) \
MACRO(6, ##__VA_ARGS__) \
REPEAT_5_(MACRO, ##__VA_ARGS__)

#define REPEAT_7_(MACRO, ...) \
MACRO(7, ##__VA_ARGS__) \
REPEAT_6_(MACRO, ##__VA_ARGS__)

#define REPEAT_8_(MACRO, ...) \
MACRO(8, ##__VA_ARGS__) \
REPEAT_7_(MACRO, ##__VA_ARGS__)

#define REPEAT_9_(MACRO, ...) \
MACRO(9, ##__VA_ARGS__) \
REPEAT_8_(MACRO, ##__VA_ARGS__)

#define REPEAT_10_(MACRO, ...) \
MACRO(10, ##__VA_ARGS__) \
REPEAT_9_(MACRO, ##__VA_ARGS__)

#define REPEAT_11_(MACRO, ...) \
MACRO(11, ##__VA_ARGS__) \
REPEAT_10_(MACRO, ##__VA_ARGS__)

#define REPEAT_12_(MACRO, ...) \
MACRO(12, ##__VA_ARGS__) \
REPEAT_11_(MACRO, ##__VA_ARGS__)

#define REPEAT_13_(MACRO, ...) \
MACRO(13, ##__VA_ARGS__) \
REPEAT_12_(MACRO, ##__VA_ARGS__)

#define REPEAT_14_(MACRO, ...) \
MACRO(14, ##__VA_ARGS__) \
REPEAT_13_(MACRO, ##__VA_ARGS__)

#define REPEAT_15_(MACRO, ...) \
MACRO(15, ##__VA_ARGS__) \
REPEAT_14_(MACRO, ##__VA_ARGS__)

#define REPEAT_16_(MACRO, ...) \
MACRO(16, ##__VA_ARGS__) \
REPEAT_15_(MACRO, ##__VA_ARGS__)

#define REPEAT_17_(MACRO, ...) \
MACRO(17, ##__VA_ARGS__) \
REPEAT_16_(MACRO, ##__VA_ARGS__)

#define REPEAT_18_(MACRO, ...) \
MACRO(18, ##__VA_ARGS__) \
REPEAT_17_(MACRO, ##__VA_ARGS__)

#define REPEAT_19_(MACRO, ...) \
MACRO(19, ##__VA_ARGS__) \
REPEAT_18_(MACRO, ##__VA_ARGS__)

#define REPEAT_20_(MACRO, ...) \
MACRO(20, ##__VA_ARGS__) \
REPEAT_19_(MACRO, ##__VA_ARGS__)

#define REPEAT_21_(MACRO, ...) \
MACRO(21, ##__VA_ARGS__) \
REPEAT_20_(MACRO, ##__VA_ARGS__)

#define REPEAT_22_(MACRO, ...) \
MACRO(22, ##__VA_ARGS__) \
REPEAT_21_(MACRO, ##__VA_ARGS__)

#define REPEAT_23_(MACRO, ...) \
MACRO(23, ##__VA_ARGS__) \
REPEAT_22_(MACRO, ##__VA_ARGS__)

#define REPEAT_24_(MACRO, ...) \
MACRO(24, ##__VA_ARGS__) \
REPEAT_23_(MACRO, ##__VA_ARGS__)

#define REPEAT_25_(MACRO, ...) \
MACRO(25, ##__VA_ARGS__) \
REPEAT_24_(MACRO, ##__VA_ARGS__)

#define REPEAT_26_(MACRO, ...) \
MACRO(26, ##__VA_ARGS__) \
REPEAT_25_(MACRO, ##__VA_ARGS__)

#define REPEAT_27_(MACRO, ...) \
MACRO(27, ##__VA_ARGS__) \
REPEAT_26_(MACRO, ##__VA_ARGS__)

#define REPEAT_28_(MACRO, ...) \
MACRO(28, ##__VA_ARGS__) \
REPEAT_27_(MACRO, ##__VA_ARGS__)

#define REPEAT_29_(MACRO, ...) \
MACRO(29, ##__VA_ARGS__) \
REPEAT_28_(MACRO, ##__VA_ARGS__)

#define REPEAT_30_(MACRO, ...) \
MACRO(30, ##__VA_ARGS__) \
REPEAT_29_(MACRO, ##__VA_ARGS__)

#define REPEAT_31_(MACRO, ...) \
MACRO(31, ##__VA_ARGS__) \
REPEAT_30_(MACRO, ##__VA_ARGS__)

#define REPEAT_32_(MACRO, ...) \
MACRO(32, ##__VA_ARGS__) \
REPEAT_31_(MACRO, ##__VA_ARGS__)

#define REPEAT_33_(MACRO, ...) \
MACRO(33, ##__VA_ARGS__) \
REPEAT_32_(MACRO, ##__VA_ARGS__)

#define REPEAT_34_(MACRO, ...) \
MACRO(34, ##__VA_ARGS__) \
REPEAT_33_(MACRO, ##__VA_ARGS__)

#define REPEAT_35_(MACRO, ...) \
MACRO(35, ##__VA_ARGS__) \
REPEAT_34_(MACRO, ##__VA_ARGS__)

#define REPEAT_36_(MACRO, ...) \
MACRO(36, ##__VA_ARGS__) \
REPEAT_35_(MACRO, ##__VA_ARGS__)

#define REPEAT_37_(MACRO, ...) \
MACRO(37, ##__VA_ARGS__) \
REPEAT_36_(MACRO, ##__VA_ARGS__)

#define REPEAT_38_(MACRO, ...) \
MACRO(38, ##__VA_ARGS__) \
REPEAT_37_(MACRO, ##__VA_ARGS__)

#define REPEAT_39_(MACRO, ...) \
MACRO(39, ##__VA_ARGS__) \
REPEAT_38_(MACRO, ##__VA_ARGS__)

#define REPEAT_40_(MACRO, ...) \
MACRO(40, ##__VA_ARGS__) \
REPEAT_39_(MACRO, ##__VA_ARGS__)

#define REPEAT_41_(MACRO, ...) \
MACRO(41, ##__VA_ARGS__) \
REPEAT_40_(MACRO, ##__VA_ARGS__)

#define REPEAT_42_(MACRO, ...) \
MACRO(42, ##__VA_ARGS__) \
REPEAT_41_(MACRO, ##__VA_ARGS__)

#define REPEAT_43_(MACRO, ...) \
MACRO(43, ##__VA_ARGS__) \
REPEAT_42_(MACRO, ##__VA_ARGS__)

#define REPEAT_44_(MACRO, ...) \
MACRO(44, ##__VA_ARGS__) \
REPEAT_43_(MACRO, ##__VA_ARGS__)

#define REPEAT_45_(MACRO, ...) \
MACRO(45, ##__VA_ARGS__) \
REPEAT_44_(MACRO, ##__VA_ARGS__)

#define REPEAT_46_(MACRO, ...) \
MACRO(46, ##__VA_ARGS__) \
REPEAT_45_(MACRO, ##__VA_ARGS__)

#define REPEAT_47_(MACRO, ...) \
MACRO(47, ##__VA_ARGS__) \
REPEAT_46_(MACRO, ##__VA_ARGS__)

#define REPEAT_48_(MACRO, ...) \
MACRO(48, ##__VA_ARGS__) \
REPEAT_47_(MACRO, ##__VA_ARGS__)

#define REPEAT_49_(MACRO, ...) \
MACRO(49, ##__VA_ARGS__) \
REPEAT_48_(MACRO, ##__VA_ARGS__)

#define REPEAT_50_(MACRO, ...) \
MACRO(50, ##__VA_ARGS__) \
REPEAT_49_(MACRO, ##__VA_ARGS__)

#define REPEAT_51_(MACRO, ...) \
MACRO(51, ##__VA_ARGS__) \
REPEAT_50_(MACRO, ##__VA_ARGS__)

#define REPEAT_52_(MACRO, ...) \
MACRO(52, ##__VA_ARGS__) \
REPEAT_51_(MACRO, ##__VA_ARGS__)

#define REPEAT_53_(MACRO, ...) \
MACRO(53, ##__VA_ARGS__) \
REPEAT_52_(MACRO, ##__VA_ARGS__)

#define REPEAT_54_(MACRO, ...) \
MACRO(54, ##__VA_ARGS__) \
REPEAT_53_(MACRO, ##__VA_ARGS__)

#define REPEAT_55_(MACRO, ...) \
MACRO(55, ##__VA_ARGS__) \
REPEAT_54_(MACRO, ##__VA_ARGS__)

#define REPEAT_56_(MACRO, ...) \
MACRO(56, ##__VA_ARGS__) \
REPEAT_55_(MACRO, ##__VA_ARGS__)

#define REPEAT_57_(MACRO, ...) \
MACRO(57, ##__VA_ARGS__) \
REPEAT_56_(MACRO, ##__VA_ARGS__)

#define REPEAT_58_(MACRO, ...) \
MACRO(58, ##__VA_ARGS__) \
REPEAT_57_(MACRO, ##__VA_ARGS__)

#define REPEAT_59_(MACRO, ...) \
MACRO(59, ##__VA_ARGS__) \
REPEAT_58_(MACRO, ##__VA_ARGS__)

#define REPEAT_60_(MACRO, ...) \
MACRO(60, ##__VA_ARGS__) \
REPEAT_59_(MACRO, ##__VA_ARGS__)

#define REPEAT_61_(MACRO, ...) \
MACRO(61, ##__VA_ARGS__) \
REPEAT_60_(MACRO, ##__VA_ARGS__)

#define REPEAT_62_(MACRO, ...) \
MACRO(62, ##__VA_ARGS__) \
REPEAT_61_(MACRO, ##__VA_ARGS__)

#define REPEAT_63_(MACRO, ...) \
MACRO(63, ##__VA_ARGS__) \
REPEAT_62_(MACRO, ##__VA_ARGS__)

#define REPEAT_64_(MACRO, ...) \
MACRO(64, ##__VA_ARGS__) \
REPEAT_63_(MACRO, ##__VA_ARGS__)

#define REPEAT_65_(MACRO, ...) \
MACRO(65, ##__VA_ARGS__) \
REPEAT_64_(MACRO, ##__VA_ARGS__)

#define REPEAT_66_(MACRO, ...) \
MACRO(66, ##__VA_ARGS__) \
REPEAT_65_(MACRO, ##__VA_ARGS__)

#define REPEAT_67_(MACRO, ...) \
MACRO(67, ##__VA_ARGS__) \
REPEAT_66_(MACRO, ##__VA_ARGS__)

#define REPEAT_68_(MACRO, ...) \
MACRO(68, ##__VA_ARGS__) \
REPEAT_67_(MACRO, ##__VA_ARGS__)

#define REPEAT_69_(MACRO, ...) \
MACRO(69, ##__VA_ARGS__) \
REPEAT_68_(MACRO, ##__VA_ARGS__)

#define REPEAT_70_(MACRO, ...) \
MACRO(70, ##__VA_ARGS__) \
REPEAT_69_(MACRO, ##__VA_ARGS__)

#define REPEAT_71_(MACRO, ...) \
MACRO(71, ##__VA_ARGS__) \
REPEAT_70_(MACRO, ##__VA_ARGS__)

#define REPEAT_72_(MACRO, ...) \
MACRO(72, ##__VA_ARGS__) \
REPEAT_71_(MACRO, ##__VA_ARGS__)

#define REPEAT_73_(MACRO, ...) \
MACRO(73, ##__VA_ARGS__) \
REPEAT_72_(MACRO, ##__VA_ARGS__)

#define REPEAT_74_(MACRO, ...) \
MACRO(74, ##__VA_ARGS__) \
REPEAT_73_(MACRO, ##__VA_ARGS__)

#define REPEAT_75_(MACRO, ...) \
MACRO(75, ##__VA_ARGS__) \
REPEAT_74_(MACRO, ##__VA_ARGS__)

#define REPEAT_76_(MACRO, ...) \
MACRO(76, ##__VA_ARGS__) \
REPEAT_75_(MACRO, ##__VA_ARGS__)

#define REPEAT_77_(MACRO, ...) \
MACRO(77, ##__VA_ARGS__) \
REPEAT_76_(MACRO, ##__VA_ARGS__)

#define REPEAT_78_(MACRO, ...) \
MACRO(78, ##__VA_ARGS__) \
REPEAT_77_(MACRO, ##__VA_ARGS__)

#define REPEAT_79_(MACRO, ...) \
MACRO(79, ##__VA_ARGS__) \
REPEAT_78_(MACRO, ##__VA_ARGS__)

#define REPEAT_80_(MACRO, ...) \
MACRO(80, ##__VA_ARGS__) \
REPEAT_79_(MACRO, ##__VA_ARGS__)

#define REPEAT_81_(MACRO, ...) \
MACRO(81, ##__VA_ARGS__) \
REPEAT_80_(MACRO, ##__VA_ARGS__)

#define REPEAT_82_(MACRO, ...) \
MACRO(82, ##__VA_ARGS__) \
REPEAT_81_(MACRO, ##__VA_ARGS__)

#define REPEAT_83_(MACRO, ...) \
MACRO(83, ##__VA_ARGS__) \
REPEAT_82_(MACRO, ##__VA_ARGS__)

#define REPEAT_84_(MACRO, ...) \
MACRO(84, ##__VA_ARGS__) \
REPEAT_83_(MACRO, ##__VA_ARGS__)

#define REPEAT_85_(MACRO, ...) \
MACRO(85, ##__VA_ARGS__) \
REPEAT_84_(MACRO, ##__VA_ARGS__)

#define REPEAT_86_(MACRO, ...) \
MACRO(86, ##__VA_ARGS__) \
REPEAT_85_(MACRO, ##__VA_ARGS__)

#define REPEAT_87_(MACRO, ...) \
MACRO(87, ##__VA_ARGS__) \
REPEAT_86_(MACRO, ##__VA_ARGS__)

#define REPEAT_88_(MACRO, ...) \
MACRO(88, ##__VA_ARGS__) \
REPEAT_87_(MACRO, ##__VA_ARGS__)

#define REPEAT_89_(MACRO, ...) \
MACRO(89, ##__VA_ARGS__) \
REPEAT_88_(MACRO, ##__VA_ARGS__)

#define REPEAT_90_(MACRO, ...) \
MACRO(90, ##__VA_ARGS__) \
REPEAT_89_(MACRO, ##__VA_ARGS__)

#define REPEAT_91_(MACRO, ...) \
MACRO(91, ##__VA_ARGS__) \
REPEAT_90_(MACRO, ##__VA_ARGS__)

#define REPEAT_92_(MACRO, ...) \
MACRO(92, ##__VA_ARGS__) \
REPEAT_91_(MACRO, ##__VA_ARGS__)

#define REPEAT_93_(MACRO, ...) \
MACRO(93, ##__VA_ARGS__) \
REPEAT_92_(MACRO, ##__VA_ARGS__)

#define REPEAT_94_(MACRO, ...) \
MACRO(94, ##__VA_ARGS__) \
REPEAT_93_(MACRO, ##__VA_ARGS__)

#define REPEAT_95_(MACRO, ...) \
MACRO(95, ##__VA_ARGS__) \
REPEAT_94_(MACRO, ##__VA_ARGS__)

#define REPEAT_96_(MACRO, ...) \
MACRO(96, ##__VA_ARGS__) \
REPEAT_95_(MACRO, ##__VA_ARGS__)

#define REPEAT_97_(MACRO, ...) \
MACRO(97, ##__VA_ARGS__) \
REPEAT_96_(MACRO, ##__VA_ARGS__)

#define REPEAT_98_(MACRO, ...) \
MACRO(98, ##__VA_ARGS__) \
REPEAT_97_(MACRO, ##__VA_ARGS__)

#define REPEAT_99_(MACRO, ...) \
MACRO(99, ##__VA_ARGS__) \
REPEAT_98_(MACRO, ##__VA_ARGS__)

#define REPEAT_100_(MACRO, ...) \
MACRO(100, ##__VA_ARGS__) \
REPEAT_99_(MACRO, ##__VA_ARGS__)

#define REPEAT_101_(MACRO, ...) \
MACRO(101, ##__VA_ARGS__) \
REPEAT_100_(MACRO, ##__VA_ARGS__)

#define REPEAT_102_(MACRO, ...) \
MACRO(102, ##__VA_ARGS__) \
REPEAT_101_(MACRO, ##__VA_ARGS__)

#define REPEAT_103_(MACRO, ...) \
MACRO(103, ##__VA_ARGS__) \
REPEAT_102_(MACRO, ##__VA_ARGS__)

#define REPEAT_104_(MACRO, ...) \
MACRO(104, ##__VA_ARGS__) \
REPEAT_103_(MACRO, ##__VA_ARGS__)

#define REPEAT_105_(MACRO, ...) \
MACRO(105, ##__VA_ARGS__) \
REPEAT_104_(MACRO, ##__VA_ARGS__)

#define REPEAT_106_(MACRO, ...) \
MACRO(106, ##__VA_ARGS__) \
REPEAT_105_(MACRO, ##__VA_ARGS__)

#define REPEAT_107_(MACRO, ...) \
MACRO(107, ##__VA_ARGS__) \
REPEAT_106_(MACRO, ##__VA_ARGS__)

#define REPEAT_108_(MACRO, ...) \
MACRO(108, ##__VA_ARGS__) \
REPEAT_107_(MACRO, ##__VA_ARGS__)

#define REPEAT_109_(MACRO, ...) \
MACRO(109, ##__VA_ARGS__) \
REPEAT_108_(MACRO, ##__VA_ARGS__)

#define REPEAT_110_(MACRO, ...) \
MACRO(110, ##__VA_ARGS__) \
REPEAT_109_(MACRO, ##__VA_ARGS__)

#define REPEAT_111_(MACRO, ...) \
MACRO(111, ##__VA_ARGS__) \
REPEAT_110_(MACRO, ##__VA_ARGS__)

#define REPEAT_112_(MACRO, ...) \
MACRO(112, ##__VA_ARGS__) \
REPEAT_111_(MACRO, ##__VA_ARGS__)

#define REPEAT_113_(MACRO, ...) \
MACRO(113, ##__VA_ARGS__) \
REPEAT_112_(MACRO, ##__VA_ARGS__)

#define REPEAT_114_(MACRO, ...) \
MACRO(114, ##__VA_ARGS__) \
REPEAT_113_(MACRO, ##__VA_ARGS__)

#define REPEAT_115_(MACRO, ...) \
MACRO(115, ##__VA_ARGS__) \
REPEAT_114_(MACRO, ##__VA_ARGS__)

#define REPEAT_116_(MACRO, ...) \
MACRO(116, ##__VA_ARGS__) \
REPEAT_115_(MACRO, ##__VA_ARGS__)

#define REPEAT_117_(MACRO, ...) \
MACRO(117, ##__VA_ARGS__) \
REPEAT_116_(MACRO, ##__VA_ARGS__)

#define REPEAT_118_(MACRO, ...) \
MACRO(118, ##__VA_ARGS__) \
REPEAT_117_(MACRO, ##__VA_ARGS__)

#define REPEAT_119_(MACRO, ...) \
MACRO(119, ##__VA_ARGS__) \
REPEAT_118_(MACRO, ##__VA_ARGS__)

#define REPEAT_120_(MACRO, ...) \
MACRO(120, ##__VA_ARGS__) \
REPEAT_119_(MACRO, ##__VA_ARGS__)

#define REPEAT_121_(MACRO, ...) \
MACRO(121, ##__VA_ARGS__) \
REPEAT_120_(MACRO, ##__VA_ARGS__)

#define REPEAT_122_(MACRO, ...) \
MACRO(122, ##__VA_ARGS__) \
REPEAT_121_(MACRO, ##__VA_ARGS__)

#define REPEAT_123_(MACRO, ...) \
MACRO(123, ##__VA_ARGS__) \
REPEAT_122_(MACRO, ##__VA_ARGS__)

#define REPEAT_124_(MACRO, ...) \
MACRO(124, ##__VA_ARGS__) \
REPEAT_123_(MACRO, ##__VA_ARGS__)

#define REPEAT_125_(MACRO, ...) \
MACRO(125, ##__VA_ARGS__) \
REPEAT_124_(MACRO, ##__VA_ARGS__)

#define REPEAT_126_(MACRO, ...) \
MACRO(126, ##__VA_ARGS__) \
REPEAT_125_(MACRO, ##__VA_ARGS__)

#define REPEAT_127_(MACRO, ...) \
MACRO(127, ##__VA_ARGS__) \
REPEAT_126_(MACRO, ##__VA_ARGS__)

#define REPEAT_128_(MACRO, ...) \
MACRO(128, ##__VA_ARGS__) \
REPEAT_127_(MACRO, ##__VA_ARGS__)

#define REPEAT_129_(MACRO, ...) \
MACRO(129, ##__VA_ARGS__) \
REPEAT_128_(MACRO, ##__VA_ARGS__)

#define REPEAT_130_(MACRO, ...) \
MACRO(130, ##__VA_ARGS__) \
REPEAT_129_(MACRO, ##__VA_ARGS__)

#define REPEAT_131_(MACRO, ...) \
MACRO(131, ##__VA_ARGS__) \
REPEAT_130_(MACRO, ##__VA_ARGS__)

#define REPEAT_132_(MACRO, ...) \
MACRO(132, ##__VA_ARGS__) \
REPEAT_131_(MACRO, ##__VA_ARGS__)

#define REPEAT_133_(MACRO, ...) \
MACRO(133, ##__VA_ARGS__) \
REPEAT_132_(MACRO, ##__VA_ARGS__)

#define REPEAT_134_(MACRO, ...) \
MACRO(134, ##__VA_ARGS__) \
REPEAT_133_(MACRO, ##__VA_ARGS__)

#define REPEAT_135_(MACRO, ...) \
MACRO(135, ##__VA_ARGS__) \
REPEAT_134_(MACRO, ##__VA_ARGS__)

#define REPEAT_136_(MACRO, ...) \
MACRO(136, ##__VA_ARGS__) \
REPEAT_135_(MACRO, ##__VA_ARGS__)

#define REPEAT_137_(MACRO, ...) \
MACRO(137, ##__VA_ARGS__) \
REPEAT_136_(MACRO, ##__VA_ARGS__)

#define REPEAT_138_(MACRO, ...) \
MACRO(138, ##__VA_ARGS__) \
REPEAT_137_(MACRO, ##__VA_ARGS__)

#define REPEAT_139_(MACRO, ...) \
MACRO(139, ##__VA_ARGS__) \
REPEAT_138_(MACRO, ##__VA_ARGS__)

#define REPEAT_140_(MACRO, ...) \
MACRO(140, ##__VA_ARGS__) \
REPEAT_139_(MACRO, ##__VA_ARGS__)

#define REPEAT_141_(MACRO, ...) \
MACRO(141, ##__VA_ARGS__) \
REPEAT_140_(MACRO, ##__VA_ARGS__)

#define REPEAT_142_(MACRO, ...) \
MACRO(142, ##__VA_ARGS__) \
REPEAT_141_(MACRO, ##__VA_ARGS__)

#define REPEAT_143_(MACRO, ...) \
MACRO(143, ##__VA_ARGS__) \
REPEAT_142_(MACRO, ##__VA_ARGS__)

#define REPEAT_144_(MACRO, ...) \
MACRO(144, ##__VA_ARGS__) \
REPEAT_143_(MACRO, ##__VA_ARGS__)

#define REPEAT_145_(MACRO, ...) \
MACRO(145, ##__VA_ARGS__) \
REPEAT_144_(MACRO, ##__VA_ARGS__)

#define REPEAT_146_(MACRO, ...) \
MACRO(146, ##__VA_ARGS__) \
REPEAT_145_(MACRO, ##__VA_ARGS__)

#define REPEAT_147_(MACRO, ...) \
MACRO(147, ##__VA_ARGS__) \
REPEAT_146_(MACRO, ##__VA_ARGS__)

#define REPEAT_148_(MACRO, ...) \
MACRO(148, ##__VA_ARGS__) \
REPEAT_147_(MACRO, ##__VA_ARGS__)

#define REPEAT_149_(MACRO, ...) \
MACRO(149, ##__VA_ARGS__) \
REPEAT_148_(MACRO, ##__VA_ARGS__)

#define REPEAT_150_(MACRO, ...) \
MACRO(150, ##__VA_ARGS__) \
REPEAT_149_(MACRO, ##__VA_ARGS__)

#define REPEAT_151_(MACRO, ...) \
MACRO(151, ##__VA_ARGS__) \
REPEAT_150_(MACRO, ##__VA_ARGS__)

#define REPEAT_152_(MACRO, ...) \
MACRO(152, ##__VA_ARGS__) \
REPEAT_151_(MACRO, ##__VA_ARGS__)

#define REPEAT_153_(MACRO, ...) \
MACRO(153, ##__VA_ARGS__) \
REPEAT_152_(MACRO, ##__VA_ARGS__)

#define REPEAT_154_(MACRO, ...) \
MACRO(154, ##__VA_ARGS__) \
REPEAT_153_(MACRO, ##__VA_ARGS__)

#define REPEAT_155_(MACRO, ...) \
MACRO(155, ##__VA_ARGS__) \
REPEAT_154_(MACRO, ##__VA_ARGS__)

#define REPEAT_156_(MACRO, ...) \
MACRO(156, ##__VA_ARGS__) \
REPEAT_155_(MACRO, ##__VA_ARGS__)

#define REPEAT_157_(MACRO, ...) \
MACRO(157, ##__VA_ARGS__) \
REPEAT_156_(MACRO, ##__VA_ARGS__)

#define REPEAT_158_(MACRO, ...) \
MACRO(158, ##__VA_ARGS__) \
REPEAT_157_(MACRO, ##__VA_ARGS__)

#define REPEAT_159_(MACRO, ...) \
MACRO(159, ##__VA_ARGS__) \
REPEAT_158_(MACRO, ##__VA_ARGS__)

#define REPEAT_160_(MACRO, ...) \
MACRO(160, ##__VA_ARGS__) \
REPEAT_159_(MACRO, ##__VA_ARGS__)

#define REPEAT_161_(MACRO, ...) \
MACRO(161, ##__VA_ARGS__) \
REPEAT_160_(MACRO, ##__VA_ARGS__)

#define REPEAT_162_(MACRO, ...) \
MACRO(162, ##__VA_ARGS__) \
REPEAT_161_(MACRO, ##__VA_ARGS__)

#define REPEAT_163_(MACRO, ...) \
MACRO(163, ##__VA_ARGS__) \
REPEAT_162_(MACRO, ##__VA_ARGS__)

#define REPEAT_164_(MACRO, ...) \
MACRO(164, ##__VA_ARGS__) \
REPEAT_163_(MACRO, ##__VA_ARGS__)

#define REPEAT_165_(MACRO, ...) \
MACRO(165, ##__VA_ARGS__) \
REPEAT_164_(MACRO, ##__VA_ARGS__)

#define REPEAT_166_(MACRO, ...) \
MACRO(166, ##__VA_ARGS__) \
REPEAT_165_(MACRO, ##__VA_ARGS__)

#define REPEAT_167_(MACRO, ...) \
MACRO(167, ##__VA_ARGS__) \
REPEAT_166_(MACRO, ##__VA_ARGS__)

#define REPEAT_168_(MACRO, ...) \
MACRO(168, ##__VA_ARGS__) \
REPEAT_167_(MACRO, ##__VA_ARGS__)

#define REPEAT_169_(MACRO, ...) \
MACRO(169, ##__VA_ARGS__) \
REPEAT_168_(MACRO, ##__VA_ARGS__)

#define REPEAT_170_(MACRO, ...) \
MACRO(170, ##__VA_ARGS__) \
REPEAT_169_(MACRO, ##__VA_ARGS__)

#define REPEAT_171_(MACRO, ...) \
MACRO(171, ##__VA_ARGS__) \
REPEAT_170_(MACRO, ##__VA_ARGS__)

#define REPEAT_172_(MACRO, ...) \
MACRO(172, ##__VA_ARGS__) \
REPEAT_171_(MACRO, ##__VA_ARGS__)

#define REPEAT_173_(MACRO, ...) \
MACRO(173, ##__VA_ARGS__) \
REPEAT_172_(MACRO, ##__VA_ARGS__)

#define REPEAT_174_(MACRO, ...) \
MACRO(174, ##__VA_ARGS__) \
REPEAT_173_(MACRO, ##__VA_ARGS__)

#define REPEAT_175_(MACRO, ...) \
MACRO(175, ##__VA_ARGS__) \
REPEAT_174_(MACRO, ##__VA_ARGS__)

#define REPEAT_176_(MACRO, ...) \
MACRO(176, ##__VA_ARGS__) \
REPEAT_175_(MACRO, ##__VA_ARGS__)

#define REPEAT_177_(MACRO, ...) \
MACRO(177, ##__VA_ARGS__) \
REPEAT_176_(MACRO, ##__VA_ARGS__)

#define REPEAT_178_(MACRO, ...) \
MACRO(178, ##__VA_ARGS__) \
REPEAT_177_(MACRO, ##__VA_ARGS__)

#define REPEAT_179_(MACRO, ...) \
MACRO(179, ##__VA_ARGS__) \
REPEAT_178_(MACRO, ##__VA_ARGS__)

#define REPEAT_180_(MACRO, ...) \
MACRO(180, ##__VA_ARGS__) \
REPEAT_179_(MACRO, ##__VA_ARGS__)

#define REPEAT_181_(MACRO, ...) \
MACRO(181, ##__VA_ARGS__) \
REPEAT_180_(MACRO, ##__VA_ARGS__)

#define REPEAT_182_(MACRO, ...) \
MACRO(182, ##__VA_ARGS__) \
REPEAT_181_(MACRO, ##__VA_ARGS__)

#define REPEAT_183_(MACRO, ...) \
MACRO(183, ##__VA_ARGS__) \
REPEAT_182_(MACRO, ##__VA_ARGS__)

#define REPEAT_184_(MACRO, ...) \
MACRO(184, ##__VA_ARGS__) \
REPEAT_183_(MACRO, ##__VA_ARGS__)

#define REPEAT_185_(MACRO, ...) \
MACRO(185, ##__VA_ARGS__) \
REPEAT_184_(MACRO, ##__VA_ARGS__)

#define REPEAT_186_(MACRO, ...) \
MACRO(186, ##__VA_ARGS__) \
REPEAT_185_(MACRO, ##__VA_ARGS__)

#define REPEAT_187_(MACRO, ...) \
MACRO(187, ##__VA_ARGS__) \
REPEAT_186_(MACRO, ##__VA_ARGS__)

#define REPEAT_188_(MACRO, ...) \
MACRO(188, ##__VA_ARGS__) \
REPEAT_187_(MACRO, ##__VA_ARGS__)

#define REPEAT_189_(MACRO, ...) \
MACRO(189, ##__VA_ARGS__) \
REPEAT_188_(MACRO, ##__VA_ARGS__)

#define REPEAT_190_(MACRO, ...) \
MACRO(190, ##__VA_ARGS__) \
REPEAT_189_(MACRO, ##__VA_ARGS__)

#define REPEAT_191_(MACRO, ...) \
MACRO(191, ##__VA_ARGS__) \
REPEAT_190_(MACRO, ##__VA_ARGS__)

#define REPEAT_192_(MACRO, ...) \
MACRO(192, ##__VA_ARGS__) \
REPEAT_191_(MACRO, ##__VA_ARGS__)

#define REPEAT_193_(MACRO, ...) \
MACRO(193, ##__VA_ARGS__) \
REPEAT_192_(MACRO, ##__VA_ARGS__)

#define REPEAT_194_(MACRO, ...) \
MACRO(194, ##__VA_ARGS__) \
REPEAT_193_(MACRO, ##__VA_ARGS__)

#define REPEAT_195_(MACRO, ...) \
MACRO(195, ##__VA_ARGS__) \
REPEAT_194_(MACRO, ##__VA_ARGS__)

#define REPEAT_196_(MACRO, ...) \
MACRO(196, ##__VA_ARGS__) \
REPEAT_195_(MACRO, ##__VA_ARGS__)

#define REPEAT_197_(MACRO, ...) \
MACRO(197, ##__VA_ARGS__) \
REPEAT_196_(MACRO, ##__VA_ARGS__)

#define REPEAT_198_(MACRO, ...) \
MACRO(198, ##__VA_ARGS__) \
REPEAT_197_(MACRO, ##__VA_ARGS__)

#define REPEAT_199_(MACRO, ...) \
MACRO(199, ##__VA_ARGS__) \
REPEAT_198_(MACRO, ##__VA_ARGS__)

#define REPEAT_200_(MACRO, ...) \
MACRO(200, ##__VA_ARGS__) \
REPEAT_199_(MACRO, ##__VA_ARGS__)

#define REPEAT_201_(MACRO, ...) \
MACRO(201, ##__VA_ARGS__) \
REPEAT_200_(MACRO, ##__VA_ARGS__)

#define REPEAT_202_(MACRO, ...) \
MACRO(202, ##__VA_ARGS__) \
REPEAT_201_(MACRO, ##__VA_ARGS__)

#define REPEAT_203_(MACRO, ...) \
MACRO(203, ##__VA_ARGS__) \
REPEAT_202_(MACRO, ##__VA_ARGS__)

#define REPEAT_204_(MACRO, ...) \
MACRO(204, ##__VA_ARGS__) \
REPEAT_203_(MACRO, ##__VA_ARGS__)

#define REPEAT_205_(MACRO, ...) \
MACRO(205, ##__VA_ARGS__) \
REPEAT_204_(MACRO, ##__VA_ARGS__)

#define REPEAT_206_(MACRO, ...) \
MACRO(206, ##__VA_ARGS__) \
REPEAT_205_(MACRO, ##__VA_ARGS__)

#define REPEAT_207_(MACRO, ...) \
MACRO(207, ##__VA_ARGS__) \
REPEAT_206_(MACRO, ##__VA_ARGS__)

#define REPEAT_208_(MACRO, ...) \
MACRO(208, ##__VA_ARGS__) \
REPEAT_207_(MACRO, ##__VA_ARGS__)

#define REPEAT_209_(MACRO, ...) \
MACRO(209, ##__VA_ARGS__) \
REPEAT_208_(MACRO, ##__VA_ARGS__)

#define REPEAT_210_(MACRO, ...) \
MACRO(210, ##__VA_ARGS__) \
REPEAT_209_(MACRO, ##__VA_ARGS__)

#define REPEAT_211_(MACRO, ...) \
MACRO(211, ##__VA_ARGS__) \
REPEAT_210_(MACRO, ##__VA_ARGS__)

#define REPEAT_212_(MACRO, ...) \
MACRO(212, ##__VA_ARGS__) \
REPEAT_211_(MACRO, ##__VA_ARGS__)

#define REPEAT_213_(MACRO, ...) \
MACRO(213, ##__VA_ARGS__) \
REPEAT_212_(MACRO, ##__VA_ARGS__)

#define REPEAT_214_(MACRO, ...) \
MACRO(214, ##__VA_ARGS__) \
REPEAT_213_(MACRO, ##__VA_ARGS__)

#define REPEAT_215_(MACRO, ...) \
MACRO(215, ##__VA_ARGS__) \
REPEAT_214_(MACRO, ##__VA_ARGS__)

#define REPEAT_216_(MACRO, ...) \
MACRO(216, ##__VA_ARGS__) \
REPEAT_215_(MACRO, ##__VA_ARGS__)

#define REPEAT_217_(MACRO, ...) \
MACRO(217, ##__VA_ARGS__) \
REPEAT_216_(MACRO, ##__VA_ARGS__)

#define REPEAT_218_(MACRO, ...) \
MACRO(218, ##__VA_ARGS__) \
REPEAT_217_(MACRO, ##__VA_ARGS__)

#define REPEAT_219_(MACRO, ...) \
MACRO(219, ##__VA_ARGS__) \
REPEAT_218_(MACRO, ##__VA_ARGS__)

#define REPEAT_220_(MACRO, ...) \
MACRO(220, ##__VA_ARGS__) \
REPEAT_219_(MACRO, ##__VA_ARGS__)

#define REPEAT_221_(MACRO, ...) \
MACRO(221, ##__VA_ARGS__) \
REPEAT_220_(MACRO, ##__VA_ARGS__)

#define REPEAT_222_(MACRO, ...) \
MACRO(222, ##__VA_ARGS__) \
REPEAT_221_(MACRO, ##__VA_ARGS__)

#define REPEAT_223_(MACRO, ...) \
MACRO(223, ##__VA_ARGS__) \
REPEAT_222_(MACRO, ##__VA_ARGS__)

#define REPEAT_224_(MACRO, ...) \
MACRO(224, ##__VA_ARGS__) \
REPEAT_223_(MACRO, ##__VA_ARGS__)

#define REPEAT_225_(MACRO, ...) \
MACRO(225, ##__VA_ARGS__) \
REPEAT_224_(MACRO, ##__VA_ARGS__)

#define REPEAT_226_(MACRO, ...) \
MACRO(226, ##__VA_ARGS__) \
REPEAT_225_(MACRO, ##__VA_ARGS__)

#define REPEAT_227_(MACRO, ...) \
MACRO(227, ##__VA_ARGS__) \
REPEAT_226_(MACRO, ##__VA_ARGS__)

#define REPEAT_228_(MACRO, ...) \
MACRO(228, ##__VA_ARGS__) \
REPEAT_227_(MACRO, ##__VA_ARGS__)

#define REPEAT_229_(MACRO, ...) \
MACRO(229, ##__VA_ARGS__) \
REPEAT_228_(MACRO, ##__VA_ARGS__)

#define REPEAT_230_(MACRO, ...) \
MACRO(230, ##__VA_ARGS__) \
REPEAT_229_(MACRO, ##__VA_ARGS__)

#define REPEAT_231_(MACRO, ...) \
MACRO(231, ##__VA_ARGS__) \
REPEAT_230_(MACRO, ##__VA_ARGS__)

#define REPEAT_232_(MACRO, ...) \
MACRO(232, ##__VA_ARGS__) \
REPEAT_231_(MACRO, ##__VA_ARGS__)

#define REPEAT_233_(MACRO, ...) \
MACRO(233, ##__VA_ARGS__) \
REPEAT_232_(MACRO, ##__VA_ARGS__)

#define REPEAT_234_(MACRO, ...) \
MACRO(234, ##__VA_ARGS__) \
REPEAT_233_(MACRO, ##__VA_ARGS__)

#define REPEAT_235_(MACRO, ...) \
MACRO(235, ##__VA_ARGS__) \
REPEAT_234_(MACRO, ##__VA_ARGS__)

#define REPEAT_236_(MACRO, ...) \
MACRO(236, ##__VA_ARGS__) \
REPEAT_235_(MACRO, ##__VA_ARGS__)

#define REPEAT_237_(MACRO, ...) \
MACRO(237, ##__VA_ARGS__) \
REPEAT_236_(MACRO, ##__VA_ARGS__)

#define REPEAT_238_(MACRO, ...) \
MACRO(238, ##__VA_ARGS__) \
REPEAT_237_(MACRO, ##__VA_ARGS__)

#define REPEAT_239_(MACRO, ...) \
MACRO(239, ##__VA_ARGS__) \
REPEAT_238_(MACRO, ##__VA_ARGS__)

#define REPEAT_240_(MACRO, ...) \
MACRO(240, ##__VA_ARGS__) \
REPEAT_239_(MACRO, ##__VA_ARGS__)

#define REPEAT_241_(MACRO, ...) \
MACRO(241, ##__VA_ARGS__) \
REPEAT_240_(MACRO, ##__VA_ARGS__)

#define REPEAT_242_(MACRO, ...) \
MACRO(242, ##__VA_ARGS__) \
REPEAT_241_(MACRO, ##__VA_ARGS__)

#define REPEAT_243_(MACRO, ...) \
MACRO(243, ##__VA_ARGS__) \
REPEAT_242_(MACRO, ##__VA_ARGS__)

#define REPEAT_244_(MACRO, ...) \
MACRO(244, ##__VA_ARGS__) \
REPEAT_243_(MACRO, ##__VA_ARGS__)

#define REPEAT_245_(MACRO, ...) \
MACRO(245, ##__VA_ARGS__) \
REPEAT_244_(MACRO, ##__VA_ARGS__)

#define REPEAT_246_(MACRO, ...) \
MACRO(246, ##__VA_ARGS__) \
REPEAT_245_(MACRO, ##__VA_ARGS__)

#define REPEAT_247_(MACRO, ...) \
MACRO(247, ##__VA_ARGS__) \
REPEAT_246_(MACRO, ##__VA_ARGS__)

#define REPEAT_248_(MACRO, ...) \
MACRO(248, ##__VA_ARGS__) \
REPEAT_247_(MACRO, ##__VA_ARGS__)

#define REPEAT_249_(MACRO, ...) \
MACRO(249, ##__VA_ARGS__) \
REPEAT_248_(MACRO, ##__VA_ARGS__)

#define REPEAT_250_(MACRO, ...) \
MACRO(250, ##__VA_ARGS__) \
REPEAT_249_(MACRO, ##__VA_ARGS__)

#define REPEAT_251_(MACRO, ...) \
MACRO(251, ##__VA_ARGS__) \
REPEAT_250_(MACRO, ##__VA_ARGS__)

#define REPEAT_252_(MACRO, ...) \
MACRO(252, ##__VA_ARGS__) \
REPEAT_251_(MACRO, ##__VA_ARGS__)

#define REPEAT_253_(MACRO, ...) \
MACRO(253, ##__VA_ARGS__) \
REPEAT_252_(MACRO, ##__VA_ARGS__)

#define REPEAT_254_(MACRO, ...) \
MACRO(254, ##__VA_ARGS__) \
REPEAT_253_(MACRO, ##__VA_ARGS__)

#define REPEAT_255_(MACRO, ...) \
MACRO(255, ##__VA_ARGS__) \
REPEAT_254_(MACRO, ##__VA_ARGS__)

// Duplicates MACRO(i, ...) for i = 1 to N, N <= 255
#define REPEAT(N, MACRO, ...) REPEAT_##N##_(MACRO, ##__VA_ARGS__)

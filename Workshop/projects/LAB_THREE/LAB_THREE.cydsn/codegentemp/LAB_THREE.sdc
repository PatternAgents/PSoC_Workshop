# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\patternagents\PSoC_Workshop\projects\LAB_THREE\LAB_THREE.cydsn\LAB_THREE.cyprj
# Date: Wed, 26 Aug 2015 21:28:40 GMT
#set_units -time ns
create_clock -name {ADC_1_intClock(FFB)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {CLK_TIMER_1(FFB)} -period 83333.333333333328 -waveform {0 41666.6666666667} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {UART_1_SCBCLK(FFB)} -period 8666.6666666666661 -waveform {0 4333.33333333333} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {Clock(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_9}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {ADC_1_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 15 31} [list]
create_generated_clock -name {CLK_TIMER_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 2001 4001} -nominal_period 83333.333333333328 [list]
create_generated_clock -name {UART_1_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 209 417} -nominal_period 8666.6666666666661 [list]
create_generated_clock -name {Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]


# Component constraints for D:\patternagents\PSoC_Workshop\projects\LAB_THREE\LAB_THREE.cydsn\TopDesign\TopDesign.cysch
# Project: D:\patternagents\PSoC_Workshop\projects\LAB_THREE\LAB_THREE.cydsn\LAB_THREE.cyprj
# Date: Wed, 26 Aug 2015 21:28:37 GMT
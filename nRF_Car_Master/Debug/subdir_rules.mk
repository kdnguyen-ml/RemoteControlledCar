################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Basic_config.obj: ../Basic_config.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmsp --abi=eabi -g --include_path="E:/Program File of Study/ti/ccsv5/ccs_base/msp430/include" --include_path="E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --advice:power=all --define=__MSP430G2533__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="Basic_config.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

LCD.obj: ../LCD.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmsp --abi=eabi -g --include_path="E:/Program File of Study/ti/ccsv5/ccs_base/msp430/include" --include_path="E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --advice:power=all --define=__MSP430G2533__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="LCD.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

NRF24L01.obj: ../NRF24L01.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmsp --abi=eabi -g --include_path="E:/Program File of Study/ti/ccsv5/ccs_base/msp430/include" --include_path="E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --advice:power=all --define=__MSP430G2533__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="NRF24L01.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

RF_Car_Master.obj: ../RF_Car_Master.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmsp --abi=eabi -g --include_path="E:/Program File of Study/ti/ccsv5/ccs_base/msp430/include" --include_path="E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --advice:power=all --define=__MSP430G2533__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="RF_Car_Master.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

UART.obj: ../UART.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/bin/cl430" -vmsp --abi=eabi -g --include_path="E:/Program File of Study/ti/ccsv5/ccs_base/msp430/include" --include_path="E:/Program File of Study/ti/ccsv5/tools/compiler/msp430_4.1.1/include" --advice:power=all --define=__MSP430G2533__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="UART.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



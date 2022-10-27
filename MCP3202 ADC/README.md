MCP3202 ADC Interface:

Used with 8051:

* How to configure the interface using C programming.

* The MCP3202 12-bit Analog-to-Digital Converter (ADC) combines high performance and low power consumption in a small package, making it ideal for embedded control applications. The MCP3202 features a successive approximation register (SAR) architecture.

- Check configuration, channel selection and timing waveform in the  ADC, Digital output.
- Chip first select low.

- Channel = channel ? 0xA0 : 0xD0;
- Channel 0 = 0xA0;
- Channel 1 = 0xD0;

- Check ADC MCP3202 manual on ADC_CLK, ADC_DI, ADC_CS(active chipset)


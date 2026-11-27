library ieee;
use ieee.std_logic_1164.all;

entity en_traffic_light is
    port
    (
        stop_sign, go_sign: std_logic;
        light: std_logic_vector(2 downto 0);
    );
end entity en_traffic_light;

architecture ar_traffic_light of en_traffic_light is
    begin
        light <= "100" when (stop_sign = '1') else "001" when (go_sign = '1') else "010";
end architecture ar_traffic_light;
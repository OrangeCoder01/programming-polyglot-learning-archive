entity demux14 is
    port 
    (
        x: in std_logic;
        sel: in std_logic_vector(1 downto 0);
        y: out st_logic_vectore(3 downto 0)
    );
end entity demux14;

architecture rtl of demux14 is
    begin
        y(0) <= x when sel = "00" else '0';
        y(1) <= x when sel = "01" else '0';
        y(2) <= x when sel = "10" else '0';
        y(3) <= x when sel = "11" else '0';
end rtl;

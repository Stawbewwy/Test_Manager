class Program_settings
{
    private:
        std::string program_name;
        std::string input_sequence;
        int num_lines_down;
        std::string chars_to_skip;
    
    public:
        Program_Settings(string, string, int, string) : program_name(string), input_sequence(string), num_lines_down(int), chars_to_skip(string);
        Program_Settings();

        void set_program_name();
        void set_input_sequence();
        void set_num_lines_down();
        void set_chars_to_skip();

        void get_program_name();
        void get_input_sequence();
        void get_num_lines_down();
        void get_chars_to_skip();
}
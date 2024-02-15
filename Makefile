CC=gcc
OBJDIR=objdir
OBJ=$(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(wildcard *.c)))
TARGET=prog
.PHONY: all clean

all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ 

clean:
	@rm -f $(TARGET) $(wildcard *.o)
	@rm -rf $(OBJDIR)

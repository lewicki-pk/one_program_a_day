class Tree
    attr_accessor :children, :node_name

    def initialize(name, children=[])
        @children = children
        @node_name = name
    end

    def visit_all(&block)
        visit &block
        children.each {|c| c.visit_all &block}
    end

    def visit(&block)
        block.call self
    end
end

ruby_tree = Tree.new( "Ruby",
                     [Tree.new("Reia"),
                      Tree.new("MyRuby")])

puts "Visiting a node"
ruby_tree.visit \
do
    |node| puts "Visiting: #{node.node_name}"
end
puts

puts "Visiting entire tree"
ruby_tree.visit_all{|node| puts "Visiting all for: #{node.node_name}"}

# Excercise:
# The Tree class was interesting, but it did not allow you to specify
# a new tree with a clean user interface. Let the initializer accept a
# nested structure with hashes and arrays. You should be able to
# specify a tree like this:
# {’grandpa’ => { ’dad’ => {’child 1’ => {}, ’child 2’ => {} }, ’uncle’ => {’child 3’ => {}, ’child 4’ => {} } } }.

class Tree
    attr_accessor :children, :node_name

    def initialize(tree = {})
        @node_name = tree.keys[0]
        @children = tree[@node_name].collect{ |k, v| Tree.new( { k => v } ) }
    end

    def visit_all(&block)
        visit &block
        children.each {|c| c.visit_all &block}
    end

    def visit(&block)
        block.call self
    end
end

# ruby_tree = Tree.new( "Ruby",
#                      [Tree.new("Reia"),
#                       Tree.new("MyRuby")])
#
# puts "Visiting a node"
# ruby_tree.visit \
# do
#     |node| puts "Visiting: #{node.node_name}"
# end
# puts
#
# puts "Visiting entire tree"
# ruby_tree.visit_all{|node| puts "Visiting all for: #{node.node_name}"}

ruby_tree = Tree.new( {"grandpa" => { "dad" => {"child 1" => {}, "child 2" => {} }, "uncle" => {"child 3" => {}, "child 4" => {} } } } )
ruby_tree.visit_all{|node| puts "Visiting all for: #{node.node_name}"}

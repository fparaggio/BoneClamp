(*
 * Just breadth-first search dudes.
 *
 * -- Allen
 *)

signature GRAPH_BREATH_FIRST_SEARCH = 
sig

   (* breadth first search *)

   val bfs : ('n,'e,'g) Graph.graph  -> 
             (Graph.node_id -> unit) ->
             ('e Graph.edge -> unit) -> 
             Graph.node_id list -> unit
   val bfsdist : ('n,'e,'g) Graph.graph -> 
                 Graph.node_id list -> (int DynArray.array * int)

end
